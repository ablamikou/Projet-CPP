#include "Deal.h"
#include "deal.h"

Deal::Deal(const std::string& dealRef, const std::string& agent, const std::list<std::string>& pool,
           const std::string& borrower, double amount, const std::string& currency,
           const std::string& startDate, const std::string& endDate, const std::string& dealStatus)
    : dealRef(dealRef), agent(agent), pool(pool), borrower(borrower),
      amount(amount), currency(currency), startDate(startDate),
      endDate(endDate), dealStatus(dealStatus) {}

Deal::~Deal(){}

void Deal::addToPool(const std::string& institution) {
    pool.push_back(institution);
}