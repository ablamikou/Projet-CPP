#ifndef PROJET_CPP_PORTFOLIO_H
#define PROJET_CPP_PORTFOLIO_H

#include <vector>
#include <string>
#include <map>

class Deal;
class Part;

class Portfolio {
private:
    Deal* dealAssociated; //Qui comporte les facilities
    std::vector<double> interestPayments;

public:
    Portfolio(Deal* deal);
    ~Portfolio();

    Deal* getDealAssociated() const;
    void addInterestPayment(double amount);
    double getTotalAmount() const;
    const std::vector<double>& getInterestPayments() const;
    void setInterestPayment(int index, double amount);
};

#endif
