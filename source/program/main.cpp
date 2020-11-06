#include <iostream>
#include "accountCtrl.hpp"

int main() {
    Base editBase; // this is an object, that will work with data base
    bool loopTest = true;
    while(loopTest) {
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
                loopTest = false;
                break;
            case('1'): //add record to file
                editBase.addRec();
                break;
            case('2'): //show record from file
                editBase.showRec();
                break;
            case('3'): //search record from file
                editBase.searchRec();
                break;
            case('4'): //update record
                editBase.updateRec();
                break;
            case('5'): //delete record
                editBase.rmRec();
                break;
            default: //there's no option, user needs to try again
                std::cout << "\nThere's no option: \"" 
                    << option
                    << "\"\nPlease try again\n\n";
        }
    }
    return 0;
}
