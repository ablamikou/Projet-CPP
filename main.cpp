#include "Company.h"
#include "Borrower.h"
#include "Lender.h"
#include "Facility.h"
#include "Deal.h"
#include <iostream>

int main() {
    // Création d'un emprunteur
    Borrower *borrower = new Borrower("Airline C1", false, "123456789");

    // Création des prêteurs
    Lender *agent = new Lender("Bank A", true, "987654321");
    Lender *lender1 = new Lender("Bank B", true, "246813579");
    Lender *lender2 = new Lender("Bank C", true, "135792468");
    Lender *lender3 = new Lender("Bank D", true, "864209753");

    // Création des facilities
    Facility *facility1 = new Facility(nullptr, "22-06-2023",
                                       "22-06-2024", 1000000, "USD");
    facility1->addLender(agent);
    facility1->addLender(lender1);

    Facility *facility2 = new Facility(nullptr, "22-06-2023",
                                       "22-06-2025", 2000000,
                                       "USD");
    facility2->addLender(lender2);
    facility2->addLender(lender3);

    // Création d'un contrat
    Deal *deal = new Deal(borrower, agent, "S1234", 3000000, "USD",
                          "22-06-2023",
                          "22-06-2028");
    deal->addFacility(facility1);
    deal->addFacility(facility2);
    deal->addPoolMember(lender1);
    deal->addPoolMember(lender2);
    deal->addPoolMember(lender3);

    // Assigner le contrat aux facilities
    facility1->setDeal(deal);
    facility2->setDeal(deal);

    // Ajout du contrat aux emprunteurs et aux prêteurs
    borrower->addDeal(deal);
    agent->addDeal(deal);
    lender1->addDeal(deal);
    lender2->addDeal(deal);
    lender3->addDeal(deal);

    // Impression des informations du contrat
    std::cout << "Contract Number: " << deal->getContractNumber() << std::endl;
    std::cout << "Borrower: " << deal->getBorrower()->getName() << std::endl;
    std::cout << "Agent: " << deal->getAgent()->getName() << std::endl;

    std::cout << "Pool Members: " << std::endl;
    for (auto &lender: deal->getPool()) {
        std::cout << lender->getName() << std::endl;
    }

    std::cout << "Facilities: " << std::endl;
    for (auto &facility: deal->getFacilities()) {
        std::cout << "Amount: " << facility->getAmount() << std::endl;
        std::cout << "Currency: " << facility->getCurrency() << std::endl;
    }

    // Libération de la mémoire
    delete deal;
    delete borrower;
}