#include "borrower.h"

Borrower::Borrower(const std::string& name) : name_(name) {}

std::string Borrower::getName() const {
    return name_;
}
