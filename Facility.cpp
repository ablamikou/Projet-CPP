#include "Facility.h"
#include "Deal.h"
#include "Lender.h"
#include <chrono>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <iomanip>

Facility::Facility(Deal* deal, const std::string& startDateString,
                   const std::string& endDateString, double amount,
                   const std::string& currency) :
        deal(deal), amount(amount), currency(currency) {

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
    return amount;
}

void Facility::setAmount(double amount) {
    this->amount = amount;
}

const std::string& Facility::getCurrency() const {
    return currency;
}

void Facility::setCurrency(const std::string& currency) {
    this->currency = currency;
}
