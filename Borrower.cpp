#include "Borrower.h"

Borrower::Borrower(const std::string& name, bool isFinancialInstitution, const std::string& siren) :
        Company(name, isFinancialInstitution, siren) { }

void Borrower::addDeal(Deal* deal) {
    deals.push_back(deal);
}

const std::vector<Deal*>& Borrower::getDeals() const {
    return deals;
}

void Borrower::setDeals(const std::vector<Deal*>& deals) {
    this->deals = deals;
}
