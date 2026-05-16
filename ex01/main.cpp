#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    std::cout << "\n\n\n\nPhoneBook Magic Deluxe Crazy Midnight Display v. 287626.27\n\n\n\n";
    while (input != "EXIT")
    {
        std::cout << "Enter a valid command\n";
        std::cout << "Available commands: ADD, SEARCH, EXIT\n";
        std::cout << "Your command: ";
        std::cin >> input;
        std::cin.ignore();
        std::cout << '\n';
        if (input == "ADD")
            phonebook.addContact();
        if (input == "SEARCH")
            phonebook.searchContact();
    }
    return (0);
}
