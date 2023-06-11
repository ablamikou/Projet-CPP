#ifndef LENDER_H
#define LENDER_H

#include <string>

class Lender {
    private:
        std::string name;

    public:
        Lender(const std::string& name);

        std::string getName() const;
};

#endif
