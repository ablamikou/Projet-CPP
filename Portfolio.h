#ifndef PROJET_CPP_PORTFOLIO_H
#define PROJET_CPP_PORTFOLIO_H

#include <vector>
#include <string>
#include <map>


class Deal;
class Part;

class Portfolio {
private:
    Deal* dealAssociated;
    std::vector<Part*> parts;
    std::map<std::string, double> interestPayments; //The string is the date of the payement


public:
    Portfolio(Deal* deal);
    ~Portfolio();

    void addPart(Part* part);
    void removePart(Part* part);

    Deal* getDealAssociated() const;
    const std::vector<Part*>& getParts() const;
    void addInterestPayment(const std::string& date, double amount);

};

#endif
