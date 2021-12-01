#include "UserConnection.hpp"

void UserConnectionFromConsole::sendMessage(const std::string& message) {
	if (message.empty()) {
		std::cout << "got an empty message!!" << std::endl;
		return;
	}

    std::cout << message;
}

ULLong UserConnectionFromConsole::readNumber(ULLong maxValue) {
    ULLong num = 0;
    bool correctInput = false;
    while(!correctInput) {
        correctInput = true;

        std::string inputNum;
        std::getline(std::cin, inputNum);
        for(char curSymbol : inputNum) {
            if(curSymbol < '0' || curSymbol > '9') {
                std::cout << "Wrong input: There's non number symbol\n"
                    << "Try again: ";
                num = 0;
                correctInput = false;
                break;
            }

            if(10 * (num  + 1) < maxValue) {
                num *= 10;
                num += (curSymbol - '0');
            } else {
                std::cout << "Wrong input: You have written big number, "
                    << "you must type numbers only less then "
                    << maxValue / 10 - 10
                    << ":\nTry again: ";
                num = 0;
                correctInput = false;
                break;
            }
        }
    }
    return num;
}

std::string UserConnectionFromConsole::readName() {
    std::string name;
    bool correctInput = false;
    while(!correctInput) {
        correctInput = true;

        std::string inputName;
        std::getline(std::cin, inputName);

        if(inputName.empty()) {
            std::cout << "Wrong input: input string is empty\n"
                << "Try again: ";
            correctInput = false;
            break;
        }
        if(inputName[0] < 'A' || inputName[0] > 'Z') {
            std::cout << "Wrong input: The name must start with a capital letter\n"
                << "Try again: ";
            correctInput = false;
        } else {
            name = inputName[0];

            for(size_t i = 1; i < inputName.size(); ++i) {
                if(inputName[i] < 'a' || inputName[i] > 'z') {
                    std::cout << "The name must start with capital letter and contain "
                        << "only the characters from 'a' to 'z'\n"
                        << "Try again: ";
                    name.clear();
                    correctInput = false;
                    break;
                }
                name += inputName[i];
            }
        }
    }
    return name;
}


char UserConnectionFromConsole::getEditOption() {
    char option;
    bool gotOption = false;

    while(!gotOption) {
        this->showEditOptions();
        option = this->readSymbol();
        
        if(option < '0' || option > '5') {
            std::cout << "\nThere's no option: \"" 
                    << option
                    << "\"\n\n";
        } else {
            gotOption = true;
        }
    }
    return option;
}

void UserConnectionFromConsole::showEditOptions() {
    std::cout << "Select one option below:\n"
            << "\t1--> Add record to file\n"
            << "\t2--> Show record from file\n"
            << "\t3--> Search record from file\n"
            << "\t4--> Update record\n"
            << "\t5--> Delete record\n"
            << "\t0--> Quit\n"
            << "Enter your choice: ";
}

char UserConnectionFromConsole::getSearchOption() {
    char option;
    bool gotOption = false;

    while(!gotOption) {
        this->showSearchOptions();
        option = this->readSymbol();
        
        if(option < '1' || option > '2') {
            std::cout << "\nThere's no option: \"" 
                    << option
                    << "\"\nPlease try again\n\n";
        } else {
            gotOption = true;
        }
    }
    return option;
}

void UserConnectionFromConsole::showSearchOptions() {
    std::cout << "Select one option below:\n"
        << "\t1--> Search a record with name\n"
        << "\t2--> Search a record with surname\n"
        << "Enter your choice: ";
}

char UserConnectionFromConsole::readSymbol() {
    char symbol;
    bool correctInput = false;
    
    while(!correctInput) {
        std::string input;
        std::getline(std::cin, input);

        if(input.size() == 1) {
            correctInput = true;
            symbol = input[0];
        } else {
            std::cout << "\nThere's wrong input,"
                << "you need to write only one symbol\n"
                << "Please try again: ";
        }
    }
    return symbol;
}
    
