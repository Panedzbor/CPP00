#pragma once

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];

    public:
        PhoneBook();
        void addContact(const std::string &name, const std::string &surname, const std::string &nickname,
                        const std::string &number, const std::string &secret);
        void searchContact(void);
};
