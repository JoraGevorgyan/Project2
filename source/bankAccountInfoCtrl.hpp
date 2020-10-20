#pragma once
#include <iostream>
#include <string>

using ULL = unsigned long long;

struct Account {
    Account();
    Account(unsigned, std::string, std::string, ULL);

private:
    unsigned num;
    std::string firstName;
    std::string lastName;
    ULL balance;
};


namespace bank {
    void addRec() {
        std::cout << "add rec\n";
    }
    void showRec() {
        std::cout << "show rec\n";
    }
    void searchRec() {
        std::cout << "search rec\n";
    }
    void updateRec() {
        std::cout << "update rec\n";
    }
    void deleteRec() {
        std::cout << "update rec\n";
    }
}
