#ifndef PROJET_CPP_PART_H
#define PROJET_CPP_PART_H

#include <chrono>
#include <string>

class Facility;

class Part {
public:
    Part(Facility* facility, const std::string& startDateString);
    ~Part();

    double getAmountPayed() const;
    void setAmoundPayed(double amount);
    void refund();
    void calculateAmount();

private:
    Facility* facility; //Comporte un deal qui comporte un borrower
    double amountPayed;
    std::chrono::system_clock::time_point dateExecution;

};

#endif