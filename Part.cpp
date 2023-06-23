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
// Vérifie si l'objet Facility est valide
    if (facility) {
        // Récupére l'objet Facility associé
        Facility* facilityObject = facility;
        double currentAmount = facilityObject->getAmount();
        if((currentAmount-amountPayed)>=0) {
            if (dateExecution < facilityObject->getStartDate()) {
                throw std::runtime_error("La date de la part est avant la date de début de la facility");
            }
            if (dateExecution > facilityObject->getEndDate()) {
                throw std::runtime_error("La date de la part est après la date de fin de la facility");
            }
            // Je calcule le temps en jour entre la date de la facilty et la date de la part
            std::chrono::duration<double> duration = dateExecution - facilityObject->getStartDate() ;
            double period = duration.count() / (24.0 * 60.0 * 60.0);
            //Ensuite je calcule l'interet à payer avec la formule suivante : (taux facility*montant facilty total)*(nb d'année)
            double interestToPay = (facilityObject->getFacilityInterest() * facilityObject->getAmount())*(period/365);
            //Je stocke ce montant calculé dans la liste repartAmount de la facility
            facilityObject->addInterestToAddPortfolio(interestToPay);
            //Je met à jour la date de la facility avec la date de la part
            facilityObject->setStartDate(dateExecution);
            // Met à jour le montant de l'objet Facility en le diminuant de amountPayed
            double refundAmount = currentAmount - amountPayed;
            facilityObject->setAmount(refundAmount);

            //Mise à jour des statuts
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
Part::~Part(){
}
