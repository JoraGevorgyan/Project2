#ifndef ACCOUNT
#define ACCOUNT

#include <iostream>
#include <string>
#include <climits>
#include "UserConnection.hpp"

class Account {
    public:
        Account(unsigned ID = {}, std::string name = {}, std::string surname = {}, ULLong balance = {});
        Account(const Account& other);
    public:
        unsigned getID() const;
        ULLong getBalance() const;
        std::string getName() const;
        std::string getSurname() const;
        void setID(unsigned ID);
        void setBalance(ULLong balance);
        void setName(std::string name);
        void setSurname(std::string surname);
        void showInfo();
        void readFromUser();
        Account operator = (const Account& other);
    private:
        UserConnection* user;
        unsigned ID;
        ULLong balance;
        std::string name;
        std::string surname;
};

#endif

