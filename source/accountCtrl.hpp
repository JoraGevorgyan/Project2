#pragma once
#include <iostream>
#include <string>
#include <utility> //for pair
#include <map>
#include "./json/single_include/nlohmann/json.hpp"

using ULLong = unsigned long long;
using json = nlohmann::json;
struct Account {
        Account();
        Account(const unsigned&, const std::string&, const std::string&, const ULLong&);
        std::istream& operator >> (std::istream&);
        std::ostream& operator << (std::ostream&);
        friend struct Base;
    protected:
        unsigned num;  //account ID
        std::string firstName;
        std::string lastName;
        ULLong balance;
};

struct Base {
        Base();
        Base(char*);
        ~Base();
        void addRec();
        void showRec();
        void searchRec();
        void updateRec();
        void rmRec();
    private:
        void showAllRecords();
        void from_json(const json&, Account&);
        void from_json(const json&, std::map< unsigned, Account >&);
        void to_json(const Account&, json&);
        void to_json(const std::map< unsigned, Account >&, json&);

        char* pathToBase;
        std::map< unsigned, Account > localBase;
        json jsonBase;
};

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

