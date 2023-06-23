#include <stdexcept>
#include "portfolio.h"
#include "deal.h"


Portfolio::Portfolio(Deal* deal) : dealAssociated(deal) {}

Portfolio::~Portfolio() {
    }

Deal* Portfolio::getDealAssociated() const {
    return dealAssociated;
}

const std::vector<double>& Portfolio::getInterestPayments() const {
    return interestPayments;
}
void Portfolio::addInterestPayment(double amount) {
    interestPayments.push_back(amount);
}

double Portfolio::getTotalAmount() const {
    double totalAmount = 0.0;
    for (double amount : interestPayments) {
        totalAmount += amount;
    }
    return totalAmount;
}
void Portfolio::setInterestPayment(int index, double amount) {
    if (index >= 0 && index < interestPayments.size()) {
        interestPayments[index] = amount;
    } else {
        throw std::out_of_range("Index hors limite");
    }
}