#include <iostream>

#include "AccountBaseCtrl.hpp"

int main() {
    std::unique_ptr<AccountBaseCtrl> editBase = std::make_unique<AccountBaseCtrl>();

    std::cout << "the program is going to be started" << std::endl;
    
    editBase->run();

    return 0;
}
