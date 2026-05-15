#include "Contact.hpp"

void Contact::setFields(const std::string &name, const std::string &surname, const std::string &nickname,
                        const std::string &number, const std::string &secret)
{
    this->name = name;
    this->surname = surname;
    this->nickname = nickname;
    this->number = number;
    this->secret = secret;
}

const std::string &Contact::getName() const
{
    return (name);
}

const std::string &Contact::getSurname() const
{
    return (surname);
}

const std::string &Contact::getNickname() const
{
    return (nickname);
}

const std::string &Contact::getNumber() const
{
    return (number);
}

const std::string &Contact::getSecret() const
{
    return (secret);
}
