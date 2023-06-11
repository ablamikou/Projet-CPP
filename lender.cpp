#include "lender.h"

Lender::Lender(const std::string& name) : name_(name) {}

std::string Lender::getName() const {
    return name_;
}
