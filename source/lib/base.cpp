#include "accountCtrl.hpp"
#include <fstream> // read and write in/on the file

/*
 * in constructors will test,
 * if data file isn't empty
 * read all data from it
 * and convert to localBase
 */
Base::Base() {  // if ther's no given file, set as default
        std::string defaultPath = "accountBase.json";
        pathToBase = defaultPath;
        std::ifstream ifs(pathToBase);
        if(ifs.peek() != EOF) {
            ifs >> inputBase;
        }
        from_json(inputBase, localBase);
    }

Base::Base(std::string path) // if there's given data file path, do the same with it
    :pathToBase(path)
    {
        std::ifstream ifs(pathToBase);
        if(ifs.peek() != EOF) {
            ifs >> inputBase;
        }
        from_json(inputBase, localBase);
    }
/*
 * upgrade base file
 * in destructor
 */
Base::~Base() {
    to_json(localBase, outputBase);
    std::ofstream ofs(pathToBase);
    ofs << outputBase;
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
    for(json::const_iterator it = j.begin(); it != j.end(); ++it) {
        std::pair< unsigned, Account > tmp;
        it->at("ID").get_to(tmp.first);
        json object{};
        it->at("object").get_to(object);
        from_json(object, tmp.second);
        container.insert(tmp);
    }
}

void Base::to_json(const std::map< unsigned, Account >& container, json& j) {
    for(std::map < unsigned, Account >::const_iterator it = container.begin();
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
    if(!localBase.insert(std::pair< unsigned, Account >(tmp.num, tmp)).second) {
        std::cout << "\nAn account with ID \"" << tmp.num << "\" already exist\n\n";
    } else {
        std::cout << "\nRecord successfully added.\n\n";
    }
}

void Base::showRec() {
    if(localBase.empty()) {
        std::cout << "There's no record\n\n";
        return;
    }
    showAllRecords();
    std::cout << "Enter the record ID, that you want to see, from the given list: ";
    unsigned num;
    std::cin >> num;
    std::map< unsigned, Account >::iterator it = localBase.find(num);
    if(it != localBase.end()) {
        std::cout << it->second << "\n";
    } else {
        std::cout << "There's no account on this ID\n";
    }
}

void Base::searchRec() {
    if(localBase.empty()) {
        std::cout << "There's no record\n\n";
        return;
    }
    bool loopTest = true;
    while(loopTest) {
        std::cout << "Select one option below to search a Record\n"
            << "        1-->Search with Record's name\n"
            << "        2-->Search with Record's surname\n"
            << "        0-->For exit\n";
        char option;
        unsigned cntr = 0; // for counting found results
        std::cin >> option;
        switch(option) {
            case '0':
                loopTest = false;
                break;
            case '1': {
                          loopTest = false;
                          std::cout << "Enter name for search: ";
                          std::string name;
                          std::cin >> name;
                          cntr = 0;
                          for(const std::pair< unsigned, Account >& current : localBase) {
                              if(current.second.firstName == name) {
                                  ++cntr;
                                  std::cout << current.first << ' ';
                              }
                          }
                          if(cntr == 0) {
                              std::cout << "no result with \"" << name << "\".\n";
                          } else {
                              std::cout << "\nThat's all we found: " << cntr << " record(s).\n";
                          }
                          break;
                      }
            case '2': {
                          loopTest = false;
                          std::cout << "Enter surname for search: ";
                          std::string surname;
                          std::cin >> surname;
                          cntr = 0;
                          for(const std::pair< unsigned, Account >& current : localBase) {
                              if(current.second.lastName == surname) {
                                  ++cntr;
                                  std::cout << current.first << ' ';
                              }
                          }
                          if(cntr == 0) {
                              std::cout << "no result with \"" << surname << "\".\n";
                          } else {
                              std::cout << "\nThat's all we found: " << cntr << " record(s).\n";
                          }
                          break;
                      }
            default: {
                         std::cout << "ther's no option\nPlease try  again\n";
                     }
        }
    }
}

void Base::updateRec() {
    if(localBase.empty()) {
        std::cout << "There's no record\n\n";
        return;
    }
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
        if(editor.num == it->first) {
            it->second = editor;
            std::cout << "\nThe record successfully updated.\n\n";
        } else {
            std::cout << "\nYou can't change account ID\n\n";
        }
    } else {
        std::cout << "\nThere's no account on this ID\n\n";
    }
}

void Base::rmRec() {
    if(localBase.empty()) {
        std::cout << "There's no record\n\n";
        return;
    }
    showAllRecords();
    std::cout << "Enter the record ID, that you want to remove, from the given list: ";
    unsigned num;
    std::cin >> num;
    std::map< unsigned, Account >::const_iterator it = localBase.find(num);
    if(it != localBase.end()) {
        std::cout << it->second;
        std::cout << "\nThe record removed\n\n";
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
