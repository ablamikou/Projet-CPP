#ifndef PROJET_CPP_FACILITY_H
#define PROJET_CPP_FACILITY_H

#include <chrono>
#include <vector>
#include <string>

// Forward declaration
class Lender;
class Deal;
class Facility {
private:
    std::vector<Lender*> lenders;
    Deal* deal;
    std::chrono::system_clock::time_point startDate;
    std::chrono::system_clock::time_point endDate;
    double amount;
    std::string currency;

public:
    Facility(Deal* deal, const std::string& startDateString,
             const std::string& endDateString, double amount,
             const std::string& currency);
    void addLender(Lender* lender);

    const std::vector<Lender*>& getLenders() const;
    void setLenders(const std::vector<Lender*>& lenders);

    Deal* getDeal() const;
    void setDeal(Deal* deal);

    const std::chrono::system_clock::time_point& getStartDate() const;
    void setStartDate(const std::chrono::system_clock::time_point& startDate);

    const std::chrono::system_clock::time_point& getEndDate() const;
    void setEndDate(const std::chrono::system_clock::time_point& endDate);

    double getAmount() const;
    void setAmount(double amount);

    const std::string& getCurrency() const;
    void setCurrency(const std::string& currency);
};


#endif //PROJET_CPP_FACILITY_H
