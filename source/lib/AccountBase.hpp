#ifndef ACCOUNT_BASE
#define ACCOUNT_BASE

#include <string>
#include <map>
#include <fstream>
#include <limits.h>

#include "json.hpp"
#include "UserConnection.hpp"
#include "Account.hpp"

using json = nlohmann::json;

class AccountBase {
    public:
        virtual ~AccountBase() {}
    public:
        virtual void addRec() = 0;
        virtual void showRec() = 0;
        virtual void searchRec() = 0;
        virtual void updateRec() = 0;
        virtual void rmRec() = 0;
};

class AccountBaseJSON : public AccountBase {
    public:
        AccountBaseJSON(std::string pathToBase = "accountBase.json");
        virtual ~AccountBaseJSON();
    public:
        virtual void addRec();
        virtual void showRec();
        virtual void searchRec();
        virtual void updateRec();
        virtual void rmRec();
    private:
        std::map< unsigned, Account > fromJsonToContainer(const json& jsonOb);
        json fromContainerToJson(const std::map< unsigned, Account >& container);
        Account fromJsonToAccount(const json& jsonObj);
        json fromAccountToJson(const Account& accountObj);
        void showIDsOfRecords();
        unsigned searchByName();
        unsigned searchBySurname();
    private:
        UserConnection* user;
        std::string pathToBase;
        std::map< unsigned, Account > localAccounts;
        json baseIn;
        json baseOut;
};

#endif

