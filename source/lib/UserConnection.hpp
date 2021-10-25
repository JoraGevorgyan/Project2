#ifndef USER_CONNECTION
#define USER_CONNECTION

#include <iostream>
#include <string>

using ULLong = unsigned long long;

class UserConnection {
    public:
        virtual void sendMessage(const std::string& message) = 0;
        
        virtual ULLong readNumber(ULLong maxValue) = 0;
        virtual std::string readName() = 0;

        virtual char getEditOption() = 0;
        virtual char getSearchOption() = 0;
};

class UserConnectionFromConsole : public UserConnection {
    public:
        virtual void sendMessage(const std::string& message);
        
        virtual ULLong readNumber(ULLong maxValue);
        virtual std::string readName();

        virtual char getEditOption();
        virtual char getSearchOption();
    private:
        void showEditOptions();
        void showSearchOptions();
        char readSymbol();
};

#endif

