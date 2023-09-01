#include "Account.hpp"
#include <iostream>
#include <ctime>
using namespace std;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() 
{
	time_t				curr_time;
	struct tm			*tm_local;

	time(&curr_time);
	tm_local = localtime(&curr_time);
	std::cout << "[" << (tm_local->tm_year + 1900);
	if (tm_local->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_mon + 1);
	if (tm_local->tm_mday < 10)
		std::cout << "0";
	std::cout << tm_local->tm_mday << "_";
	if (tm_local->tm_hour < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_hour);
	if (tm_local->tm_min < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_min);
	if (tm_local->tm_sec < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_sec) << "] ";
	
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int deposit)
{
    this->_amount = deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = getNbAccounts();
    _totalAmount += deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:" << _amount << 
        ";created" << std::endl;
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<
        ";amount:" << this->_amount <<
        ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 
void	Account::makeDeposit( int deposit )
{
    this->_amount = this->_amount + deposit;
    this->_nbDeposits++;
	_totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<
        ";p_amount:" << this->_amount - deposit <<
        ";deposit:" << deposit <<
        ";amount:" << this->_amount<<
        ";nb_deposits:" << this->_nbDeposits << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<
        ";p_amount:" << this->_amount;
    if (withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        this->_amount = this->_amount - withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
	    _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal <<
            ";amount:" << this->_amount <<
            ";nb_withdrawals" << this->_nbWithdrawals << std::endl;
        return (true);
    }
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<
        ";amount:" << this->_amount <<
        ";deposits:" << this->_nbDeposits <<
        ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() <<
        ";total:" << getTotalAmount() <<
        ";deposits:" << getNbDeposits() <<
        ";withdrawals:" << getNbWithdrawals() << std::endl;
}