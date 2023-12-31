#ifndef DEAL_H
#define DEAL_H

#include <chrono>
#include <string>
#include <vector>
#include "Portfolio.h"

class Borrower;
class Lender;
class Facility;
class Portfolio;

class Deal {
private:
    Borrower* borrower;
    Lender* agent;
    std::vector<Lender*> pool;
    std::vector<Facility*> facilities;
    std::string contractNumber;
    double projectAmount;
    std::string currency;
    std::chrono::system_clock::time_point contractStartDate;
    std::chrono::system_clock::time_point contractEndDate;
    std::string status; //mettre a jour
    Portfolio* portfolio;

public:
    Deal(Borrower* borrower, Lender* agent, const std::string& contractNumber, double projectAmount,
    const std::string& currency, const std::string& contractStartDateStr,
    const std::string& contractEndDateStr);

    ~Deal();

    void addPoolMember(Lender* lender);
    void addFacility(Facility* facility);

    Borrower* getBorrower() const;
    void setBorrower(Borrower* borrower);

    Lender* getAgent() const;
    void setAgent(Lender* agent);

    Portfolio* getPortfolio() const;
    void setPortfolio(Portfolio *portfolio);

    const std::vector<Lender*>& getPool() const;
    void setPool(const std::vector<Lender*>& pool);

    const std::vector<Facility*>& getFacilities() const;
    void setFacilities(const std::vector<Facility*>& facilities);

    const std::string& getContractNumber() const;
    void setContractNumber(const std::string& contractNumber);

    double getProjectAmount() const;
    void setProjectAmount(double projectAmount);
    const std::string& getCurrency() const;
    void setCurrency(const std::string& currency);

    const std::chrono::system_clock::time_point& getContractStartDate() const;
    void setContractStartDate(const std::chrono::system_clock::time_point& contractStartDate);

    const std::chrono::system_clock::time_point& getContractEndDate() const;
    void setContractEndDate(const std::chrono::system_clock::time_point& contractEndDate);

    const std::string& getStatus() const;
    void setStatus(const std::string& status);
    void updateStatus();
    void refundInterests(double amount); //rembourse une partie des intérêts
    void refundInterests(); //rembourse tous les intérêts
};

#endif
