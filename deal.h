#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <list>
#include "lender.h"
#include "borrower.h"


class Deal {

private:
    std::string dealRef;
    Lender agent;
    std::list<Borrower> pool;
    Borrower borrower;
    double amount;
    std::string currency;
    std::string startDate;
    std::string endDate;
    std::string dealStatus;

public:
    Deal(std::string& dealRef, Lender& agent, std::list<Borrower>& pool,
        Borrower& borrower, double projectAmount, std::string& currency,
        std::string& startDate, std::string& endDate, std::string& dealStatus);
    
    ~Deal();
    void afficher();

    void addToPool(const std::string& bank);

};

#endif
