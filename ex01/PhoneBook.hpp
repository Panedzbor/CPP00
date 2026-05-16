#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     counter;
        void    saveNewContact(const std::string &name, const std::string &surname, const std::string &nickname,
                        const std::string &number, const std::string &secret);
        void    collectContactInfo(std::string &name, std::string &surname, std::string &nickname,
                                    std::string &number, std::string &secret);
        void    displayAllContacts() const;
        void    displaySelectedContact(int i) const;
        unsigned int askForIndex() const;

    public:
        PhoneBook() : counter(0) {};
        void addContact(void);
        void searchContact(void) const;
};

#endif