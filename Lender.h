#ifndef LENDER_H
#define LENDER_H

#include "Company.h"
#include <vector>

class Facility;
class Deal;

class Lender : public Company {
private:
    std::vector<Facility*> facilities;
    std::vector<Deal*> deals;

public:
    Lender(const std::string& name, bool isFinancialInstitution, const std::string& siren);
    ~Lender();
    void addDeal(Deal* deal);
    void addFacility(Facility* facility);

    const std::vector<Facility*>& getFacilities() const;
    void setFacilities(const std::vector<Facility*>& facilities);

    const std::vector<Deal*>& getDeals() const;
    void setDeals(const std::vector<Deal*>& deals);
};


#endif
