#ifndef PROJET_CPP_FACILITY_H
#define PROJET_CPP_FACILITY_H

#include <chrono>
#include <vector>
#include <string>
#include <map>

class Lender;
class Deal;
class Facility {
private:
    std::vector<Lender*> lenders;
    Deal* deal;
    std::chrono::system_clock::time_point startDate;
    std::chrono::system_clock::time_point endDate;
    double amountTotal;
    std::string currency; //peut être différente de la devise du deal
    double facilityInterest;
    std::vector<double> interestToAddPortfolio;
    //Pour savoir quel lender à donner combien
    std::map<Lender*, double> repartAmount;
public:
    const std::map<Lender *, double> &getRepartAmount() const;


public:
    Facility(Deal* deal, const std::string& startDateString,
             const std::string& endDateString, double amount,
             const std::string& currency);
    
    ~Facility();

    void addLender(Lender* lender);

    const std::vector<Lender*>& getLenders() const;
    void setLenders(const std::vector<Lender*>& lenders);

    Deal* getDeal() const;
    void setDeal(Deal* deal);

    double getFacilityInterest() const;
    void setFacilityInterest(double facilityInterest);

    const std::chrono::system_clock::time_point& getStartDate() const;
    void setStartDate(const std::chrono::system_clock::time_point& startDate);

    const std::chrono::system_clock::time_point& getEndDate() const;
    void setEndDate(const std::chrono::system_clock::time_point& endDate);

    double getAmount() const;
    void setAmount(double amount);

    const std::string& getCurrency() const;
    void setCurrency(const std::string& currency);

    void addLenderContribution(Lender* lender, double contribution);

    const std::vector<double> getInterestToAddPortfolio() const;
};


#endif
