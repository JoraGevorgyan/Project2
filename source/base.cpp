#include "accountCtrl.hpp"
#include <fstream>

/*
 * in constructors will test,
 * if data file isn't empty
 * read all data from it
 * and convert to localBase
 */
Base::Base() // if ther's no given file, set as default
    :pathToBase("accountBase.json")
    {
        std::ifstream ifs(pathToBase);
        if(ifs.peek() != EOF) {
            ifs >> jsonBase;
        }
        from_json(jsonBase, localBase);
    }

Base::Base(char* path) // if there's given data file path, do the same with it
    :pathToBase(path)
    {
        std::ifstream ifs(pathToBase);
        if(ifs.peek() != EOF) {
            ifs >> jsonBase;
        }
        from_json(jsonBase, localBase);
    }
/*
 * upgrade base file
 * in destructor
 */
Base::~Base() {
    to_json(localBase, jsonBase);
    std::ofstream ofs(pathToBase);
    ofs << jsonBase;
}

/*
 * this f-ns will conver
 * from json object to Account object (from_json)
 * and the same in reverce other (to_json)
 */
void Base::from_json(const json& j, Account& obj) {
    j.at("num").get_to(obj.num);
    j.at("firstName").get_to(obj.firstName);
    j.at("lastName").get_to(obj.lastName);
    j.at("balance").get_to(obj.balance);
}

void Base::to_json(const Account& obj, json& j) {
    j["num"] = obj.num;
    j["firstName"] = obj.firstName;
    j["lastName"] = obj.lastName;
    j["balance"] = obj.balance;
}

/*
 * this f-ns will convert
 * from json object to chosen container (from_json)
 * and the same in reverse other (to_json)
 */
void Base::from_json(const json& j, std::map< unsigned, Account >& container) {
    for(json::iterator it = j.begin(); it != j.end(); ++it) {
        std::pair< unsigned, Account > tmp;
        it->at["ID"].get_to(tmp.first);
        json object{};
        it->at["object"].get_to(object);
        from_json(object, tmp.second);
        container.insert(tmp);
}

void Base::to_json(const std::map< unsigned, Account >& container, json& j) {
    for(std::map < unsigned, Account >::iterator it = container.begin();
            it != container.end(); ++it) {
        json cur{}, object{};
        to_json(it->second, object);
        cur["ID"] = it->first;
        cur["object"] = object;
        j += cur;
    }
}


void Base::addRec() {
    Account tmp;
    std::cin >> tmp;
    if(!.localBase.insert(std::pair< unsigned, Account >(tmp.num, tmp)).second) {
        std::cout << "An account with ID \"" << tmp.first << "\" already exist\n";
    }
}

void Base::showRec() {
    showAllRecords();
    std::cout << "Enter the record ID, that you want to see, from the given list: ";
    unsigned num;
    std::cin >> num;
    std::map< unsigned, Account >::iterator it = localBase.find(num);
    if(it != localBase.end()) {
        std::cout << it->second;
    } else {
        std::cout << "There's no account on this ID\n";
    }
}

void Base::searchRec() {
    std::cout << "Select one option below to search a Record\n"
        << "        1-->Search with Record's name\n"
        << "        2-->Search with Record's surname\n"
        << "        0-->For exit\n";
    char option;
    std::cin >> option;
    switch(option) {
        case 0:
            break;
        case 1:
            std::cout << "Enter name for search: ";
            std::string name;
            std::cin >> name;
            unsigned cntr = 0;
            for(const std::pair< unsigned, Account >& current : localBase) {
                if(current.second.firstName == name) {
                    ++cntr;
                    std::cout << current.first << ' ';
                }
            }
            if(cntr == 0) {
                std::cout << "no result with \"" << name << "\".\n";
            } else {
                std::cout << "That's all we found: " << cntr << " record(s).\n";
            }
            break;
        case 2:
            std::cout << "Enter surname for search: ";
            std::string surname;
            std::cin >> surname;
            unsigned cntr = 0;
            for(const std::pair< unsigned, Account >& current : localBase) {
                if(current.second.lastName == surname) {
                    ++cntr;
                    std::cout << current.first << ' ';
                }
            }
            if(cntr == 0) {
                std::cout << "no result with \"" << surname << "\".\n";
            } else {
                std::cout << "That's all we found: " << cntr << " record(s).\n";
            }
            break;
        default:
            std::cout << "ther's no option\n";
    }
}

void Base::updateRec() {
    showAllRecords();
    std::cout << "Enter the record ID, that you want to edit, from the given list: ";
    unsigned num;
    std::cin >> num;
    std::map< unsigned, Account >::iterator it = localBase.find(num);
    if(it != localBase.end()) {
        std::cout << "Record " << num << " has following data:\n";
        std::cout << it->second;
        std::string tmp(40, '_');
        std::cout << tmp
            << "\nEnter data to modify\n\n";
        Account editor;
        std::cin >> editor;
        it->second = editor;
    } else {
        std::cout << "There's no account on this ID\n";
    }
}

void Base::rmRec() {
    showAllRecords();
    std::cout << "Enter the record ID, that you want to remove, from the given list: ";
    unsigned num;
    std::map< unsigned, Account >::iterator it = localBase.find(num);
    if(it != localBase.end()) {
        std::cout << "The record with data :\n";
        std::cout << it->second;
        std::cout << "\nwas removed\n";
        localBase.erase(it);
    } else {
        std::cout << "There's no account on this ID\n";
    }
}

void Base::showAllRecords() {
    std::cout << "There is(are) "
        << localBase.size()
        << " recorde(s) :\n";
    /*
     * show all IDs from container
     */
    for(const std::pair< unsigned, Account >& current : localBase) {
        std::cout << current.first << ' ';
    }
    std::cout << "\n";
}
    

