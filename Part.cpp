#include "Part.h"
#include "Facility.h"
#include "Deal.h"
#include <chrono>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>


Part::Part(Facility* facility, const std::string& dateString)
    : facility(facility) {
    std::istringstream dateStringStream(dateString);
    std::tm dateStruct = {};

    if (!(dateStringStream >> std::get_time(&dateStruct, "%d-%m-%Y"))) {
        throw std::runtime_error("Invalid date format, expected dd-MM-yyyy");
    }
    std::chrono::system_clock::time_point dateExecution = std::chrono::system_clock::from_time_t(std::mktime(&dateStruct));
    this->dateExecution = dateExecution;
}

double Part::getAmountPayed() const {
    return amountPayed;
}
void Part::setAmoundPayed(double amount) {
    this->amountPayed=amount;
}

void Part::refund() {

    if (facility) {
        
        double currentAmount = facility->getAmount();
        if((currentAmount-amountPayed)>=0) {
            if (dateExecution < facility->getStartDate()) {
                throw std::runtime_error("La date de la part est avant la date de début de la facility");
            }
            if (dateExecution > facility->getEndDate()) {
                throw std::runtime_error("La date de la part est après la date de fin de la facility");
            }
            //Calcule du temps en jour entre la date de la facilty et la date de la part
            std::chrono::duration<double> duration = dateExecution - facility->getStartDate() ;
            double period = duration.count() / (24.0 * 60.0 * 60.0);
            //Interet à payer avec la formule suivante : (taux facility*montant facilty total)*(nb d'année)
            double interestToPay = (facility->getFacilityInterest() * facility->getAmount())*(period/365);
            facility->getDeal()->getPortfolio()->addInterestPayment(interestToPay);

            // Met à jour le montant de l'objet Facility en le diminuant de amountPayed
            double refundAmount = currentAmount - amountPayed;
            facility->setAmount(refundAmount);

            Deal* deal = facility->getDeal();
            if (deal != nullptr) {
                deal->updateStatus();
            }else{
                throw std::invalid_argument("Aucun deal associé");
            }
        }else{
            throw std::invalid_argument("Le montant payé est supérieur au montant qu'on doit");
    }
}
}

Part::~Part(){}
