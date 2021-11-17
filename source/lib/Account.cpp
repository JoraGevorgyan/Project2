#include "Account.hpp"

Account::Account(unsigned ID, std::string name, std::string surname, ULLong balance)
    :ID(ID)
     ,balance(balance)
     ,name(name)
     ,surname(surname)
{
    UserConnectionFromConsole* userFromConsole = new UserConnectionFromConsole();
    this->user = userFromConsole;
}

Account::Account(const Account& other)
    :ID(other.ID)
     ,balance(other.balance)
     ,name(other.name)
     ,surname(other.surname)
{
    this->user = other.user;
}

unsigned Account::getID() const {
    return this->ID;
}

ULLong Account::getBalance() const {
    return this->balance;
}

std::string Account::getName() const {
    return this->name;
}

std::string Account::getSurname() const {
    return this->surname;
}

void Account::setID(unsigned ID) {
    this->ID = ID;
}

void Account::setBalance(ULLong balance) {
    this->balance = balance;
}

void Account::setName(std::string name) {
    this->name = name;
}

void Account::setSurname(std::string surname) {
    this->surname = surname;
}

void Account::showInfo() {
    this->user->sendMessage("\nThe record has following data:\n");
    this->user->sendMessage("Account Number(ID): " + std::to_string(this->ID) + "\n");
    this->user->sendMessage("First Name: " + this->name + "\n");
    this->user->sendMessage("Last Name: " + this->surname + "\n");
    this->user->sendMessage("Current Balance: " + std::to_string(this->balance) + "\n\n");
}
void Account::readFromUser() {
    this->user->sendMessage("Enter account number: ");
    this->ID = this->user->readNumber(UINT_MAX);

    this->user->sendMessage("Enter First Name: ");
    this->name = this->user->readName();

    this->user->sendMessage("Enter Last Name: ");
    this->surname = this->user->readName();

    this->user->sendMessage("Enter Balance: ");
    this->balance = this->user->readNumber(ULLONG_MAX);
}

Account Account::operator = (const Account& other) {
    this->ID = other.ID;
    this->balance = other.balance;
    this->name = other.name;
    this->surname = other.surname;
    return *this;
}
