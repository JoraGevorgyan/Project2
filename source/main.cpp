#include <iostream>
#include "bankAccountInfoCtrl.hpp"

int main() {
    std::cout << "***Account Information System***\n";
    while(true) {
        std::cout << "Select one option below\n"
            << "        1--> Add record to file\n"
            << "        2--> Show record from file\n"
            << "        3--> Search record from file\n"
            << "        4--> Update record\n"
            << "        5--> Delete record\n"
            << "        0--> Quit\n"
            << "Enter your choice: ";
        char option;
        std::cin >> option;
        switch(option) {
            case('0'): // quit program
                return 0;
            case('1'): //add record to file
                bank::addRec();
                break;
            case('2'): //show record from file
                bank::showRec();
                break;
            case('3'): //search record from file
                bank::searchRec();
                break;
            case('4'): //update record
                bank::updateRec();
                break;
            case('5'): //delete record
                bank::deleteRec();
                break;
            default: //there's no option, user needs to try again
                std::cout << "There's no option, that you have chosen.\nPlease try again\n\n";
        }
    }
}
