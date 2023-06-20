#include "Company.h"

Company::Company(const std::string& name, bool isFinancialInstitution, const std::string& siren) :
        name(name), isFinancialInstitution(isFinancialInstitution), siren(siren) { }

const std::string& Company::getName() const {
    return name;
}

void Company::setName(const std::string& name) {
    this->name = name;
}

bool Company::isAFinancialInstitution() const {
    return isFinancialInstitution;
}

void Company::setIsFinancialInstitution(bool isFinancialInstitution) {
    this->isFinancialInstitution = isFinancialInstitution;
}

const std::string& Company::getSiren() const {
    return siren;
}

void Company::setSiren(const std::string& siren) {
    this->siren = siren;
}
