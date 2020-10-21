#pragma once
#include <iostream>
#include <string>
#include <vector>

using ULLong = unsigned long long;

struct Account {
        Account();
        Account(const unsigned&, const std::string&, const std::string&, const ULLong&);
        std::istream& operator >> (std::istream&);
        std::ostream& operator << (std::ostream&);
    protected:
        unsigned num;  //account ID
        std::string firstName;
        std::string lastName;
        ULLong balance;
};
/*
struct  AccountBase : public Account {
        AccountBase(std::string);
    private:
        friend Account searchRec(unsigned);
        friend unsigned addRec(const Account&);
        friend int rmRec(unsigned);
        int baseFileDescriptor;
        std::vector< int > listofID;
};
*/


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
    void rmRec() {
        std::cout << "update rec\n";
    }
}
