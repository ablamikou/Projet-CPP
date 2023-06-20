#ifndef BORROWER_H
#define BORROWER_H

#include "Company.h"
#include <vector>
class Deal;

class Borrower : public Company {
private:
    std::vector<Deal*> deals;

public:
    Borrower(const std::string& name, bool isFinancialInstitution, const std::string& siren);
    //Ajoute un deal a la liste
    void addDeal(Deal* deal);

    const std::vector<Deal*>& getDeals() const;
    //Remplace la liste entière des deals
    void setDeals(const std::vector<Deal*>& deals);
};

#endif
