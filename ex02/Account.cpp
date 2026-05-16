#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "created";
    std::cout << '\n';
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "closed";
    std::cout << '\n';
    _nbAccounts--;
    _totalAmount -= checkAmount();
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << '\n';
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(nullptr);
    std::tm *tm = std::localtime(&t);
    std::cout << '[' << std::put_time(tm, "%Y%m%d_%H%M%S") << "] ";
}

int	Account::checkAmount( void ) const
{
    return (_amount);
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << checkAmount() << ';';
    std::cout << "deposit:" << deposit << ';';
    _amount += deposit;
    _nbDeposits++;
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "nb_deposits:" << _nbDeposits;
    std::cout << '\n';
    _totalNbDeposits++;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << checkAmount() << ';';
    if (withdrawal > checkAmount())
    {
        std::cout << "withdrawal:refused\n";
        return (false);
    }
    std::cout << "withdrawal:" << withdrawal << ';';
    _amount -= withdrawal;
    _nbWithdrawals++;
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals;
    std::cout << '\n';
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    return (true);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ';';
    std::cout << "total:" << getTotalAmount() << ';';
    std::cout << "deposits:" << getNbDeposits() << ';';
    std::cout << "withdrawals:" << getNbWithdrawals();
    std::cout << '\n';
}

int Account::getNbAccounts(void)        
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)       
{ 
    return _totalAmount; 
}

int Account::getNbDeposits(void)        
{ 
    return _totalNbDeposits; 
}

int Account::getNbWithdrawals(void)     
{ 
    return _totalNbWithdrawals; 
}