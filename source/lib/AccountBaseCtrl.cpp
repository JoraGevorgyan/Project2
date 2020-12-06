#include "AccountBaseCtrl.hpp"

AccountBaseCtrl::AccountBaseCtrl() {
    AccountBaseJSON* accountBaseJSON = new AccountBaseJSON();
    this->accountBase = accountBaseJSON;

    UserConnectionFromConsole* userFromConsole = new UserConnectionFromConsole();
    this->user = userFromConsole; 
}

AccountBaseCtrl::~AccountBaseCtrl() {
    delete this->accountBase;
    delete this->user;
}

void AccountBaseCtrl::run() {
    bool exitLoop = false;

    while(!exitLoop) {
        char editOption = this->user->getEditOption();

        switch(editOption) {
            case('0'): {
                           exitLoop = true;
                           break;
                       }
            case('1'): {
                           this->accountBase->addRec();
                           break;
                       }
            case('2'): {
                           this->accountBase->showRec();
                           break;
                       }
            case('3'): {
                           this->accountBase->searchRec();
                           break;
                       }
            case('4'): {
                           this->accountBase->updateRec();
                           break;
                       }
            case('5'): {
                           this->accountBase->rmRec();
                           break;
                       }
        }
    }
}
