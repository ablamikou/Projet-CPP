#ifndef PROJET_CPP_PART_H
#define PROJET_CPP_PART_H

class Lender;
class Deal;

class Part {
public:
    Part(Deal* deal, Lender* lender, float pourcentage);
    ~Part();

    double getInterestTotal() const;
    bool refundInterest(double amount);


private:
    Deal* deal;
    Lender* lender;
    float pourcentage;
    double interestTotal;
    double interestPayed;
    double interestNotPayedYet;

    void calculateInterest();
};

#endif