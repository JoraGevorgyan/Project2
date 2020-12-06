#include <iostream>
#include "AccountBaseCtrl.hpp"

int main() {
    AccountBaseCtrl* editBase = new AccountBaseCtrl;
    
    editBase->run();
    
    delete editBase;
    return 0;
}
