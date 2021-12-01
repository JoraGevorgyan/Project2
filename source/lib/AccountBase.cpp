#include "AccountBase.hpp"

AccountBaseJSON::AccountBaseJSON(std::string pathToBase)
    :pathToBase(pathToBase)
{

    try
    {
        UserConnectionFromConsole* userFromConsole = new UserConnectionFromConsole();
        this->user = userFromConsole;

        std::ifstream ifs(this->pathToBase);
        if(ifs.peek() != EOF) {
            ifs >> this->baseIn;
        }
        ifs.close();
        this->localAccounts = fromJsonToContainer(this->baseIn);
    }
    catch(json::parse_error& err) {
        this->user->sendMessage("Thrown exception: " + std::string(err.what()) + "\n");
        this->user->sendMessage("Now all data is deleted\n\n");
    }
    catch(json::out_of_range& err) {
        this->user->sendMessage("Thrown exception: " + std::string(err.what()) + "\n");
        this->user->sendMessage("Now all data is deleted\n\n");
    }
    catch(json::type_error& err) {
        this->user->sendMessage("Thrown exception: " + std::string(err.what()) + "\n");
        this->user->sendMessage("Now all data is deleted\n\n");
    }
}

AccountBaseJSON::~AccountBaseJSON() {
    this->baseOut = this->fromContainerToJson(this->localAccounts);
    std::ofstream ofs(this->pathToBase);
    ofs << this->baseOut;
    ofs.close();
}

void AccountBaseJSON::addRec() {
    Account tmp;
    tmp.readFromUser();

    if (!this->localAccounts.insert(std::pair< unsigned, Account >(tmp.getID(), tmp)).second) {
        this->user->sendMessage("\nAn account with that ID already exist!\n\n");
    } else {
        this->user->sendMessage("\nRecord successfully added.\n\n");
    }
}

void AccountBaseJSON::showRec() {
    if (this->localAccounts.empty()) {
        this->user->sendMessage("There's no record!\n\n");
        return;
    }
    this->showIDsOfRecords();
    this->user->sendMessage("Choose the record ID from the given list, that you want to see: ");
    unsigned customID = (unsigned) this->user->readNumber(UINT_MAX);

    std::map< unsigned, Account >::iterator fit = this->localAccounts.find(customID);
    if (fit != this->localAccounts.end()) {
        fit->second.showInfo();
    } else {
        this->user->sendMessage("There's no account on that ID\n\n");
    }
}

void AccountBaseJSON::searchRec() {
    if(this->localAccounts.empty()) {
        this->user->sendMessage("There's no record!\n");
        return;
    }
    char searchOption = this->user->getSearchOption();
    
    unsigned foundNamesCount;
    switch(searchOption) {
        case('1'): {
                       foundNamesCount = this->searchByName();
                       break;
                   }
        case('2'): {
                       foundNamesCount = this->searchBySurname();
                       break;
                   }
    }

    if(foundNamesCount == 0) {
        this->user->sendMessage("No results!\n\n");
    } else {
        this->user->sendMessage("\nFound " + std::to_string(foundNamesCount) + " result(s)\n\n");
    }
}

unsigned AccountBaseJSON::searchByName() {
    this->user->sendMessage("Enter name for search: ");
    std::string customName = this->user->readName();
    unsigned foundNamesCount = 0;
    for(const std::pair< unsigned, Account >& tmp : localAccounts) {
        if(tmp.second.getName() == customName) {
            this->user->sendMessage(std::to_string(tmp.first) + " ");
            ++foundNamesCount;
        }
    }
    return foundNamesCount;
}

unsigned AccountBaseJSON::searchBySurname() {
    this->user->sendMessage("Enter surname for search: ");
    std::string customName = this->user->readName();
    unsigned foundNamesCount = 0;

    for(const std::pair< unsigned, Account >& tmp : localAccounts) {
        if(tmp.second.getSurname() == customName) {
            this->user->sendMessage(std::to_string(tmp.first) + " ");
            ++foundNamesCount;
        }
    }
    return foundNamesCount;
}

void AccountBaseJSON::updateRec() {
    if(this->localAccounts.empty()) {
        this->user->sendMessage("There's no record!\n\n");
        return;
    }
    
    this->showIDsOfRecords();
    this->user->sendMessage("Enter the record ID, that you want to edit, from the given list: ");
    unsigned customID = (unsigned) this->user->readNumber(UINT_MAX);
    
    std::map< unsigned, Account >::iterator fit = this->localAccounts.find(customID);
    if(fit == this->localAccounts.end()) {
        this->user->sendMessage("There's no record on that ID\n\n");
        return;
    }
    
    fit->second.showInfo();
    this->user->sendMessage(std::string(40, '_') + "\n");
    this->user->sendMessage("Enter data to modify\n");
    
    Account newAccount;
    newAccount.readFromUser();
    if(newAccount.getID() != fit->second.getID()) {
        this->user->sendMessage("\nYou can't change account ID\n\n");
        return;
    }
    fit->second = newAccount;
    this->user->sendMessage("\nThe record successfully updated.\n\n");
}

void AccountBaseJSON::rmRec() {
    if(this->localAccounts.empty()) {
        this->user->sendMessage("There's no record!\n\n");
        return;
    }
    
    this->showIDsOfRecords();
    this->user->sendMessage("Enter the record ID, that you want to remove, from the given list: ");
    unsigned customID = (unsigned) this->user->readNumber(UINT_MAX);

    std::map< unsigned, Account >::iterator fit = this->localAccounts.find(customID);
    if(fit == this->localAccounts.end()) {
        this->user->sendMessage("There's no account to remove!\n\n");
    } else {
        fit->second.showInfo();
        this->localAccounts.erase(fit);
        this->user->sendMessage("The preceding record removed\n\n");
    }
}

void AccountBaseJSON::showIDsOfRecords() {
    this->user->sendMessage("We have " + std::to_string(this->localAccounts.size()) + " record(s):\n");
    for(const std::pair< unsigned, Account >& current : this->localAccounts) {
        this->user->sendMessage(std::to_string(current.first) + " ");
    }
    this->user->sendMessage("\n");
}

#define ACCOUNT_OBJ_ID "objID"
#define ACCOUNT_OBJ_BODY "objBody"
#define ACCOUNT_ID "ID"
#define ACCOUNT_NAME "name"
#define ACCOUNT_SURNAME "surname"
#define ACCOUNT_BALANCE "balance"

std::map< unsigned, Account > AccountBaseJSON::fromJsonToContainer(const json& jsonObj) {
    std::map< unsigned, Account > container;

    for(json::const_iterator it = jsonObj.begin(); it != jsonObj.end(); ++it) {
        unsigned curID;
        Account curObj;
        json curJsonObj;
        it->at(ACCOUNT_OBJ_ID).get_to(curID);
        it->at(ACCOUNT_OBJ_BODY).get_to(curJsonObj);

        curObj = this->fromJsonToAccount(curJsonObj);

        container.insert(std::pair< unsigned, Account >(curID, curObj));
    }
    return container;
}

json AccountBaseJSON::fromContainerToJson(const std::map< unsigned, Account >& container) {
    json jsonObj{};

    for(std::map < unsigned, Account >::const_iterator it = container.begin();
            it != container.end(); ++it) {

        json curJsonAccountObj = this->fromAccountToJson(it->second);
        json curJsonObj{};
        curJsonObj[ACCOUNT_OBJ_ID] = it->first;
        curJsonObj[ACCOUNT_OBJ_BODY] = curJsonAccountObj;
        
        jsonObj += curJsonObj;
    }
    return jsonObj;
}

Account AccountBaseJSON::fromJsonToAccount(const json& jsonObj) {
    Account accountObj;

    unsigned curID;
    std::string curName;
    ULLong curBalance;

    jsonObj.at(ACCOUNT_ID).get_to(curID);
    accountObj.setID(curID);

    jsonObj.at(ACCOUNT_NAME).get_to(curName);
    accountObj.setName(curName);

    jsonObj.at(ACCOUNT_SURNAME).get_to(curName);
    accountObj.setSurname(curName);

    jsonObj.at(ACCOUNT_BALANCE).get_to(curBalance);
    accountObj.setBalance(curBalance);
    
    return accountObj;
}

json AccountBaseJSON::fromAccountToJson(const Account& accountObj) {
    json jsonObj{};

    jsonObj[ACCOUNT_ID] = accountObj.getID();
    jsonObj[ACCOUNT_NAME] = accountObj.getName();
    jsonObj[ACCOUNT_SURNAME] = accountObj.getSurname();
    jsonObj[ACCOUNT_BALANCE] = accountObj.getBalance();

    return jsonObj;
}

