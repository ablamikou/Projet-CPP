#include "Company.h"
#include "Borrower.h"
#include "Lender.h"
#include "Facility.h"
#include "Deal.h"
#include "Part.h"
#include <iostream>

int main() {
    // Création d'un emprunteur
    Borrower *borrower = new Borrower("Anwar & Mikou Holding", false, "123456789");

    // Création des prêteurs
    Lender *agent = new Lender("BNP Paribas", true, "987654321");
    Lender *lender1 = new Lender("Societe generale", true, "246813579");
    Lender *lender2 = new Lender("Credit agricole", true, "135792468");
    Lender *lender3 = new Lender("Natixis", true, "864209753");

    // Création des facilities
    Facility *facility1 = new Facility(nullptr, "22-06-2023",
                                       "22-06-2024", 1000000, "USD");
    facility1->addLender(agent);
    facility1->addLender(lender1);

    Facility *facility2 = new Facility(nullptr, "20-03-2023",
                                       "22-06-2025", 2000000,
                                       "USD");
    facility2->addLender(lender2);
    facility2->addLender(lender3);

/* //Affichage des contributions par lender
    facility1->addLenderContribution(lender1,20);
    facility1->addLenderContribution(lender1,30);
    facility1->addLenderContribution(lender2,30);
    facility1->addLenderContribution(lender3,20);
    std::map<Lender *, double> contrib = facility1->getRepartAmount();
    // Afficher le contenu du vecteur
    std::cout << "Contenu des contrib : ";
    for (const auto& pair : contrib) {
        Lender* lender = pair.first;
        double amount = pair.second;

        std::cout << "Lender: " << lender << ", Contribution: " << amount << std::endl;
    }
    std::cout << std::endl;
*/
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
        std::cout << "\t" << lender->getName() << std::endl;
    }

    std::cout << std::endl << "Facilities: " << std::endl;
    for (auto &facility: deal->getFacilities()) {
        std::cout << "\t" << "Amount: " << facility->getAmount() << std::endl;
        std::cout << "\t" << "Currency: " << facility->getCurrency() << std::endl;
    }

    Portfolio *portfolio1=new Portfolio(deal);
    deal->setPortfolio(portfolio1);


    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "Montant initial: " << facility1->getAmount() << std::endl;
    //Première part payée
    Part *part1=new Part(facility1,"22-12-2023");
    part1->setAmoundPayed(600000);
    part1->refund();
    std::cout << "Montant restant apres part 1: " << facility1->getAmount() << std::endl;
    //Deuxième part payée
    Part *part2=new Part(facility1,"10-04-2024");
    part2->setAmoundPayed(400000);
    part2->refund();
    std::cout << "Montant restant apres part 2: " << facility1->getAmount() << std::endl;

/*
    std::vector<double> interestVector = facility1->getInterestToAddPortfolio();

    // Afficher le contenu du vecteur
    std::cout << "Contenu de interestToAddPortfolio de facility1 : ";
    for (const auto& interest : interestVector) {
        std::cout << interest << " ";
    }
    std::cout << std::endl;
*/
    std::cout << "Montant dans le portfolio: " << portfolio1->getTotalAmount() << std::endl;
    std::cout << "Statut du deal apres remboursement de la premiere facilty: " << deal->getStatus() << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;

    std::cout << std::endl << "Montant initial: " << facility2->getAmount() << std::endl;
    //Première part payée
    Part *part3 =new Part(facility2,"01-01-2024");
    part3->setAmoundPayed(600000);
    part3->refund();
    std::cout << "Montant restant apres part 3 : " << facility2->getAmount() << std::endl;
    //Deuxième part payée
    Part *part4=new Part(facility2,"05-04-2024");
    part4->setAmoundPayed(1400000);
    part4->refund();
    std::cout << "Montant restant apres part 4 : " << facility2->getAmount() << std::endl;


    std::cout << "Montant dans le portfolio: " << portfolio1->getTotalAmount() << std::endl;

    deal->refundInterests(100000.0);
    std::cout << "Montant dans le portfolio apres remboursement : " << portfolio1->getTotalAmount() << std::endl;

    std::cout << "statut du deal: " << deal->getStatus() << std::endl;

    delete deal;
    delete borrower;
    delete lender1;
    delete lender2;
    delete lender3;
    delete agent;
    delete part1;
    delete part2;
    delete part3;
    delete part4;
    delete facility2;
    delete facility1;
    delete portfolio1;
}