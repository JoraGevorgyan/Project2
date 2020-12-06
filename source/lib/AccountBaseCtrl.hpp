#ifndef ACCOUNT_BASE_CTRL
#define ACCOUNT_BASE_CTRL

#include "AccountBase.hpp"
#include "UserConnection.hpp"

class AccountBaseCtrl {
    private:
        AccountBase* accountBase;
        UserConnection* user;

    public:
        AccountBaseCtrl();
        ~AccountBaseCtrl();
        void run();
};

#endif

