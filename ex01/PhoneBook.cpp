#include <iomanip>
#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

static void truncateAndPrint(std::string str);

void PhoneBook::addContact(void)
{
    std::string name;
    std::string surname;
    std::string nickname;
    std::string number;
    std::string secret;

    collectContactInfo(name, surname, nickname, number, secret);
    saveNewContact(name, surname, nickname, number, secret);
}

void PhoneBook::collectContactInfo(std::string &name, std::string &surname, std::string &nickname,
                                    std::string &number, std::string &secret)
{
    std::cout << "__Collecting contact info__\n";
    std::cout << "Enter contact name: ";
    std::getline(std::cin, name);
    while (name.empty())
    {
        std::cout << "Enter contact name: ";
        std::getline(std::cin, name);
    }
    std::cout << "Enter contact surname: ";
    std::getline(std::cin, surname);
    while (surname.empty())
    {
        std::cout << "Enter contact surname: ";
        std::getline(std::cin, surname);
    }
    std::cout << "Enter contact nickname: ";
    std::getline(std::cin, nickname);
    while (nickname.empty())
    {
        std::cout << "Enter contact nickname: ";
        std::getline(std::cin, nickname);
    }
    std::cout << "Enter contact number: ";
    std::getline(std::cin, number);
    while (number.empty())
    {
        std::cout << "Enter contact number: ";
        std::getline(std::cin, number);
    }
    std::cout << "Enter contact darkest secret: ";
    std::getline(std::cin, secret);
    while (secret.empty())
    {
        std::cout << "Enter contact darkest secret: ";
        std::getline(std::cin, secret);
    }
}

void PhoneBook::saveNewContact(const std::string &name, const std::string &surname, const std::string &nickname,
                        const std::string &number, const std::string &secret)
{
    contacts[counter++].setFields(name, surname, nickname, number, secret);
    std::cout << "Contact saved\n\n";
    if (counter == 8)
        counter = 0;
}

void PhoneBook::searchContact(void) const
{
    std::cout << std::right;
    displayAllContacts();
    unsigned int i = askForIndex();
    displaySelectedContact(i);
}

void PhoneBook::displayAllContacts() const
{
    std::string str;

    for (int i = 0; i < 8; i++)
    {
        if (!contacts[i].getName().empty())
        {
            std::stringstream ss;

            ss << (i + 1);
            str = ss.str();
            truncateAndPrint(str);
            std::cout << '|';
            truncateAndPrint(contacts[i].getName());
            std::cout << '|';
            truncateAndPrint(contacts[i].getSurname());
            std::cout << '|';
            truncateAndPrint(contacts[i].getNickname());
            std::cout << "\n";
        }
    }
    if (!contacts[0].getName().empty())
        std::cout << '\n';
}

static void truncateAndPrint(std::string str)
{
    if (str.size() > 10)
    {
        str.resize(9);
        str.append(".");
    }
    std::cout << std::setw(10) << str;
}

unsigned int PhoneBook::askForIndex(void) const
{
    unsigned int i = 0;

    std::cout << "Type in the contact's index you want to see: ";
    while (!(std::cin >> i) || i < 1 || i > 8)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Wrong index.\n";
        std::cout << "Type in the contact's index you want to see: ";
    }
    std::cout << '\n';
    return (i - 1);
}

void PhoneBook::displaySelectedContact(int i) const
{
    std::cout << std::setw(17) << "Name: ";
    std::cout << contacts[i].getName() << '\n';
    std::cout << std::setw(17) << "Surname: ";
    std::cout << contacts[i].getSurname() << '\n';
    std::cout << std::setw(17) << "Nickname: ";
    std::cout << contacts[i].getNickname() << '\n';
    std::cout << std::setw(17) << "Tel. no: ";
    std::cout << contacts[i].getNumber() << '\n';
    std::cout << std::setw(17) << "Darkest Secret: ";
    std::cout << contacts[i].getSecret() << '\n';
    std::cout << '\n';
}
