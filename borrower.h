#ifndef BORROWER_H
#define BORROWER_H

#include <string>

class Borrower {

    private:
        std::string name;

    public:
        Borrower(const std::string& name);

        std::string getName() const;
};
#endif
