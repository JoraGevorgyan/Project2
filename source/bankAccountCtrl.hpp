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
/*this function will be used for Account's istream operator*/
template <class type>
std::pair<type, bool> getNumber(std::string str, type maxSize) {
    maxSize /= 10;
    std::pair<type, bool> res(0, true);
    for(char c : str) {
        if(c < '0' || c > '9') {
            if(c != '.') {
                res.second = false;
                std::cout << "There's non number symbol, please try again and type number\n";
                return res;
            }
             /*
              * after '.' symbols are ignored,
              * in the future I can add here code, that'll convert them to double
              */
            std::cout << "symbols after '.' are ignored\n";
             return res;
        }
        if(res.first < maxSize) {
            res.first = res.first * 10 + c - '0';
        } else {
            res.second = false;
            std::cout << "You have written big number, you can type\n"
                << "numbers only less then "
                << maxSize
                << "\nplease try again\n";
            return res;
        }
    }
    return res;
}

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
