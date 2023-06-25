#include "Deal.h"
#include "Borrower.h"
#include "Lender.h"
#include "Facility.h"
#include <regex>
#include <sstream>
#include <iomanip>

Deal::Deal(Borrower* borrower, Lender* agent, const std::string& contractNumber, double projectAmount,
           const std::string& currency, const std::string& contractStartDateStr,
           const std::string& contractEndDateStr) {

    //Control of the contract number
std::regex contractNumberPattern("[SZB]\\d{4}");
if(!std::regex_match(contractNumber, contractNumberPattern)){
throw std::invalid_argument("The contract number is not in the correct format. It should be one these letters (S,Z,B) followed by 4 numbers");
}
//Control of the dates
    std::tm contractStartDate = {};
    std::istringstream contractStartDateStream(contractStartDateStr);
    contractStartDateStream >> std::get_time(&contractStartDate, "%d-%m-%Y");

    if (contractStartDateStream.fail()) {
        throw std::runtime_error("Date is not in the correct format (dd-MM-yyyy)");
    }

    std::tm contractEndDate = {};
    std::istringstream contractEndDateStream(contractEndDateStr);
    contractEndDateStream >> std::get_time(&contractEndDate, "%d-%m-%Y");

    if (contractEndDateStream.fail()) {
        throw std::runtime_error("Date is not in the correct format (dd-MM-yyyy)");
    }

    if (std::difftime(std::mktime(&contractStartDate), std::mktime(&contractEndDate)) > 0) {
        throw std::runtime_error("Start date must be before end date");
    }

this->borrower = borrower;
this->agent = agent;
this->contractNumber = contractNumber;
this->projectAmount = projectAmount;
this->currency = currency;
this->contractStartDate = std::chrono::system_clock::from_time_t(std::mktime(&contractStartDate));
this->contractEndDate = std::chrono::system_clock::from_time_t(std::mktime(&contractEndDate));
}

void Deal::addPoolMember(Lender* lender) {
    pool.push_back(lender);
}

void Deal::addFacility(Facility* facility) {
    facilities.push_back(facility);
}

Borrower* Deal::getBorrower() const {
    return borrower;
}

Portfolio* Deal::getPortfolio() const {
    return portfolio;
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
void Deal::setPortfolio(Portfolio *portfolio) {
    this->portfolio=portfolio;
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

void Deal::updateStatus() {
    double totalFacilitiesAmount = 0.0;
    for (Facility* facility : facilities) {
        totalFacilitiesAmount += facility->getAmount();
    }

    double totalPortfolioAmount = 0.0;
    if (portfolio) {
        totalPortfolioAmount = portfolio->getTotalAmount();
    }else {
        throw std::invalid_argument("Le portfolio n'existe pas");
    }

    if (totalFacilitiesAmount == 0.0 && totalPortfolioAmount == 0.0) {
        status = "terminated";
    } else {
        status = "close";
    }
}
void Deal::refundInterests(double amount) {
    Portfolio* portfolio = getPortfolio();
    const std::vector<double>& interestPayments = portfolio->getInterestPayments();
    if(amount>portfolio->getTotalAmount()){
        throw std::invalid_argument("Le montant est supérieur au montant total des intérêts");
    }else {
    for (int i = 0; i < interestPayments.size(); i++) {
        if (amount >= interestPayments[i]) {
            amount -= interestPayments[i];
            portfolio->setInterestPayment(i, 0.0);
        } else {
            portfolio->setInterestPayment(i, interestPayments[i] - amount);
            amount = 0.0;
            break;
        }
    }
    }
    updateStatus();
    }
void Deal::refundInterests() {
    Portfolio* portfolio = getPortfolio();
    const std::vector<double>& interestPayments = portfolio->getInterestPayments();
    for (int i = 0; i < interestPayments.size(); i++) {
        portfolio->setInterestPayment(i, 0.0);
    }
    updateStatus();
}



