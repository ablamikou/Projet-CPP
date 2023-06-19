#ifndef PROJET_CPP_COMPANY_H
#define PROJET_CPP_COMPANY_H

#include <string>


class Company {
protected:
    std::string name;
    bool isFinancialInstitution;
    std::string siren;

public:
    Company(const std::string& name, bool isFinancialInstitution, const std::string& siren);

    const std::string& getName() const;
    void setName(const std::string& name);

    bool isAFinancialInstitution() const;
    void setIsFinancialInstitution(bool isFinancialInstitution);

    const std::string& getSiren() const;
    void setSiren(const std::string& siren);
};

#endif //PROJET_CPP_COMPANY_H
