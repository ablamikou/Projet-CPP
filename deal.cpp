#include "Deal.h"
#include "deal.h"

Deal::Deal(std::string& dealRef, Lender& agent, std::list<Borrower>& pool,
            Borrower& borrower, double amount,  std::string& currency,
            std::string& startDate,  std::string& endDate,  std::string& dealStatus)
    : dealRef(dealRef), agent(agent), pool(pool), borrower(borrower),
      amount(amount), currency(currency), startDate(startDate),
      endDate(endDate), dealStatus(dealStatus) {}

Deal::~Deal(){}

void Deal::addToPool(const std::string& institution) {
    pool.push_back(institution);
}