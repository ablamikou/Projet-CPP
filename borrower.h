#ifndef BORROWER_H
#define BORROWER_H

#include <string>

class Borrower {
public:
    Borrower(const std::string& name);

    std::string getName() const;

private:
    std::string name_;
};
#endif
