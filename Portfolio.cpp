#include "portfolio.h"
#include "deal.h"
#include "part.h"

Portfolio::Portfolio(Deal* deal) : dealAssociated(deal) {}

Portfolio::~Portfolio() {
    for (Part* part : parts) {
        delete part;
    }
}

void Portfolio::addPart(Part* part) {
    parts.push_back(part);
}

void Portfolio::removePart(Part* part) {
    auto it = std::find(parts.begin(), parts.end(), part);
    if (it != parts.end()) {
        parts.erase(it);
        delete part;
    }
}

Deal* Portfolio::getDealAssociated() const {
    return dealAssociated;
}

const std::vector<Part*>& Portfolio::getParts() const {
    return parts;
}

void Portfolio::addInterestPayment(const std::string& date, double amount) {
    interestPayments[date] = amount;
}