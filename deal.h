#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <list>

class Deal {

private:
    std::string dealRef;
    std::string agent;
    std::list<std::string> pool;
    std::string borrower;
    double amount;
    std::string currency;
    std::string startDate;
    std::string endDate;
    std::string dealStatus;

public:
    Deal(const std::string& dealRef, const std::string& agent, const std::list<std::string>& pool,
         const std::string& borrower, double projectAmount, const std::string& currency,
         const std::string& startDate, const std::string& endDate, const std::string& dealStatus);
    
    ~Deal();
    void afficher();

    void addToPool(const std::string& bank);

};

#endif
