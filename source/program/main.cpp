#include <iostream>
#include "AccountBaseCtrl.hpp"

int main() {
    AccountBaseCtrl* editBase = new AccountBaseCtrl;


    std::cout << "the program is going to be started" << std::endl;
    
    editBase->run();
    
    delete editBase;
    return 0;
}
