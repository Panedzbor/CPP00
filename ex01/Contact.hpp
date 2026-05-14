#pragma once

#include <string>

class Contact
{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string number;
        std::string secret;
    
    public:
        void setFields(const std::string &name, const std::string &surname, const std::string &nickname,
                        const std::string &number, const std::string &secret);
        const std::string &getName() const;
        const std::string &getSurname() const;
        const std::string &getNickname() const;
        const std::string &getNumber() const;
        const std::string &getSecret() const;
};