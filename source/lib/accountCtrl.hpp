#pragma once
#include <iostream> //for input/output
#include <string>
#include <utility> //for pair
#include <map>     // for local container
#include "json.hpp"

/*
 * you need to ignore these 
 * "main.cpp"
 *"account.cpp"
 *"base.cpp"
 */

using ULLong = unsigned long long;
using json = nlohmann::json;

struct Account {
        Account();
        Account(const unsigned& num, const std::string& firstName
                , const std::string& lastName, const ULLong& balance);
        friend std::istream& operator >> (std::istream& in, Account& a);
        friend std::ostream& operator << (std::ostream& out, const Account& a);
        friend struct Base;
    protected:
        unsigned num;  //account ID
        std::string firstName;
        std::string lastName;
        ULLong balance;
};

struct Base {
        /*
         * default constructor will
         * open "accountBase.json" file (and create it, if not exist)
         * and will read all data from file and convert it into the localBasse
         */
        Base();
        Base(std::string path); // the same as default, but the file is given as afgument
        /*
         * destructor will
         * convert all data from localBase to outputBase
         * and write it in the file
         */
        ~Base();
        void addRec();
        void showRec();
        void searchRec();
        void updateRec();
        void rmRec();
    private:
        void showAllRecords(); //shows all record's IDs from local base
        void from_json(const json& j, Account& obj);
        void from_json(const json& j, std::map< unsigned, Account >& container);
        void to_json(const Account& obj, json& j);
        void to_json(const std::map< unsigned, Account >& container, json& j);

        std::string pathToBase;
        std::map< unsigned, Account > localBase;
        json inputBase;
        json outputBase;
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

