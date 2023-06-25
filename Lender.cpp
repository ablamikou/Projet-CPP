#include "Lender.h"
#include "Deal.h"
//#include "Facility.h"

Lender::Lender(const std::string& name, bool isFinancialInstitution, const std::string& siren) :
        Company(name, isFinancialInstitution, siren) {
            if (!isFinancialInstitution) {
        throw std::runtime_error("Erreur : le lender doit être une institution financière");
    }
         }

void Lender::addDeal(Deal* deal) {
    deals.push_back(deal);
}
/*
void Lender::addFacility(Facility* facility) {
    facilities.push_back(facility);
}

const std::vector<Facility*>& Lender::getFacilities() const {
    return facilities;
}

void Lender::setFacilities(const std::vector<Facility*>& facilities) {
    this->facilities = facilities;
}
 */
const std::vector<Deal*>& Lender::getDeals() const {
    return deals;
}

void Lender::setDeals(const std::vector<Deal*>& deals) {
    this->deals = deals;
}

