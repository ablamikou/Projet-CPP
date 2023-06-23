#include "Part.h"

Part::Part(Deal* deal, Lender* lender, float pourcentage)
    : deal(deal), lender(lender), pourcentage(pourcentage) {
    calculateInterest();
}

double Part::getInterestTotal() const {
    return interestTotal;
}

void Part::calculateInterest() {
    double amount = deal->getProjectAmount();
    interestTotal = (amount * pourcentage) / 100.0;
    interestNotPayedYet = interestTotal;
    interestPayed = 0;
}

bool Part::refundInterest(double amount) {
    if (amount <= interestNotPayed) {
        interestNotPayed -= amount;
        interestPayed += amount;
        return true;
    }
    return false;
}

Part::~Part()