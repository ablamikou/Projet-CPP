#include "Deal.h"

Deal::Deal(Borrower* borrower, Lender* agent, const std::string& contractNumber, double projectAmount,
           const std::string& currency, const std::chrono::system_clock::time_point& contractStartDate,
           const std::chrono::system_clock::time_point& contractEndDate) :
        borrower(borrower), agent(agent), contractNumber(contractNumber), projectAmount(projectAmount),
        currency(currency), contractStartDate(contractStartDate), contractEndDate(contractEndDate) { }

void Deal::addPoolMember(Lender* lender) {
    pool.push_back(lender);
}

void Deal::addFacility(Facility* facility) {
    facilities.push_back(facility);
}

Borrower* Deal::getBorrower() const {
    return borrower;
}

void Deal::setBorrower(Borrower* borrower) {
    this->borrower = borrower;
}

Lender* Deal::getAgent() const {
    return agent;
}

void Deal::setAgent(Lender* agent) {
    this->agent = agent;
}

const std::vector<Lender*>& Deal::getPool() const {
    return pool;
}

void Deal::setPool(const std::vector<Lender*>& pool) {
    this->pool = pool;
}

const std::vector<Facility*>& Deal::getFacilities() const {
    return facilities;
}

void Deal::setFacilities(const std::vector<Facility*>& facilities) {
    this->facilities = facilities;
}

const std::string& Deal::getContractNumber() const {
    return contractNumber;
}

void Deal::setContractNumber(const std::string& contractNumber) {
    this->contractNumber = contractNumber;
}

double Deal::getProjectAmount() const {
    return projectAmount;
}

void Deal::setProjectAmount(double projectAmount) {
    this->projectAmount = projectAmount;
}

const std::string& Deal::getCurrency() const {
    return currency;
}

void Deal::setCurrency(const std::string& currency) {
    this->currency = currency;
}

const std::chrono::system_clock::time_point& Deal::getContractStartDate() const {
    return contractStartDate;
}

void Deal::setContractStartDate(const std::chrono::system_clock::time_point& contractStartDate) {
    this->contractStartDate = contractStartDate;
}

const std::chrono::system_clock::time_point& Deal::getContractEndDate() const {
    return contractEndDate;
}

void Deal::setContractEndDate(const std::chrono::system_clock::time_point& contractEndDate) {
    this->contractEndDate = contractEndDate;
}

const std::string& Deal::getStatus() const {
    return status;
}

void Deal::setStatus(const std::string& status) {
    this->status = status;
}
