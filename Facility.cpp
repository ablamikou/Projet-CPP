#include "Facility.h"

Facility::Facility(Deal* deal, const std::chrono::system_clock::time_point& startDate,
                   const std::chrono::system_clock::time_point& endDate, double amount,
                   const std::string& currency) :
        deal(deal), startDate(startDate), endDate(endDate), amount(amount), currency(currency) { }

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
