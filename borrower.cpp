#include "borrower.h"

Borrower::Borrower(const std::string& name) : name(name) {}

std::string Borrower::getName() const {
    return name;
}