#include "Facility.h"
#include "Deal.h"
#include "Lender.h"
#include "Portfolio.h"
#include <chrono>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>
#include<math.h>

Facility::Facility(Deal* deal, const std::string& startDateString,
                   const std::string& endDateString, double amount,
                   const std::string& currency) :
        deal(deal), amountTotal(amount), currency(currency), facilityInterest(0.05), interestToAddPortfolio() {
    // Convert string to time_point
    std::istringstream startDateStream(startDateString);
    std::istringstream endDateStream(endDateString);
    std::tm startDateStruct = {};
    std::tm endDateStruct = {};

    if (!(startDateStream >> std::get_time(&startDateStruct, "%d-%m-%Y")) || !(endDateStream >> std::get_time(&endDateStruct, "%d-%m-%Y"))) {
        throw std::runtime_error("Invalid date format, expected dd-MM-yyyy");
    }

    std::chrono::system_clock::time_point startDate = std::chrono::system_clock::from_time_t(std::mktime(&startDateStruct));
    std::chrono::system_clock::time_point endDate = std::chrono::system_clock::from_time_t(std::mktime(&endDateStruct));

    // Check if start date is before end date
    if (startDate >= endDate) {
        throw std::runtime_error("Start date must be before end date");
    }

    this->startDate = startDate;
    this->endDate = endDate;
}

void Facility::addLender(Lender* lender) {
    lenders.push_back(lender);
}
void Facility::addInterestToAddPortfolio(double amount) {
    interestToAddPortfolio.push_back(amount);
}

const std::vector<Lender*>& Facility::getLenders() const {
    return lenders;
}

void Facility::setLenders(const std::vector<Lender*>& lenders) {
    this->lenders = lenders;
}

Deal* Facility::getDeal() const {
    return deal;
}

void Facility::setDeal(Deal* deal) {
    this->deal = deal;
}

const std::vector<double> Facility::getInterestToAddPortfolio() const{
    return interestToAddPortfolio;
}
double Facility::getFacilityInterest() const{
    return facilityInterest;
}
void Facility::setFacilityInterest(double facilityInterest) {
    this->facilityInterest=facilityInterest;
}
const std::chrono::system_clock::time_point& Facility::getStartDate() const {
    return startDate;
}

void Facility::setStartDate(const std::chrono::system_clock::time_point& startDate) {
    this->startDate = startDate;
}

const std::chrono::system_clock::time_point& Facility::getEndDate() const {
    return endDate;
}

void Facility::setEndDate(const std::chrono::system_clock::time_point& endDate) {
    this->endDate = endDate;
}

double Facility::getAmount() const {
    return amountTotal;
}

void Facility::setAmount(double amount) {
    this->amountTotal = amount;
}

const std::string& Facility::getCurrency() const {
    return currency;
}

void Facility::setCurrency(const std::string& currency) {
    this->currency = currency;
}

void Facility::addLenderContribution(Lender* lender, double contribution) {
    if (contribution <= 100.0 and contribution >= 0.0) {
        double currentSum = 0.0;
        for (const auto &pair: repartAmount) {
            currentSum += pair.second;
        }

        if (currentSum + contribution > 100.0) {
            // La somme dépasse 100, signaler une erreur
            std::cout << "Erreur : La somme des contributions dépasse 100%" << std::endl;
        } else {
            repartAmount[lender] = contribution;
            std::cout << "Couple ajouté à repation des lenders : Lender = " << lender->getName()
                      << ", Contribution = " << contribution << std::endl;
            std::cout << "Info : La nouvelle contribution est de " << currentSum + contribution << " %." << std::endl;
        }
    } else {
        throw std::invalid_argument("La contribution doit être un pourcentage valide (entre 0 et 100)");
    }
}
    void Facility::insertInPortfolio() {
        // Vérifie si le deal associé existe
        if (!deal) {
            throw std::runtime_error("Aucun deal associé à la facility");
        }

        // Récupère le portfolio associé au deal
        Portfolio* portfolio = deal->getPortfolio();
        if (!portfolio) {
            throw std::runtime_error("Aucun portfolio associé au deal");
        }

        // Ajoute les intérêts stockés dans interestToAddPortfolio au portfolio
        for (double interest : interestToAddPortfolio) {
            portfolio->addInterestPayment(interest);
        }
        // Efface les intérêts stockés dans interestToAddPortfolio
        interestToAddPortfolio.clear();
    }
