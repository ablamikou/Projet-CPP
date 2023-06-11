#ifndef LENDER_H
#define LENDER_H

#include <string>

class Lender {
public:
    Lender(const std::string& name);

    std::string getName() const;

private:
    std::string name_;
};

#endif
