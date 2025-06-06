#include "Account.hpp"

Account::Account()
{
	this->balance = 0;
	return ;
}

Account::Account(double initial_balance)
{
	this->balance = initial_balance;
	return ;
}

Account::Account(const Account& other)
{
	this->balance = other.balance;
	return ;
}

Account::~Account()
{
	std::cout << "Destructor Called" << std::endl;
	return ;
}


double	Account::get_balance() const
{
	return (this->balance);
}

void	Account::make_deposit(double deposit)
{
	this->balance += deposit;
	return ;
}

void	Account::withdraw_balance(double withdraw)
{
	this->balance -= withdraw;
	return ;
}

void	Account::add_interet(double interet)
{
	this->balance = this->balance * (1 + interet);
	return ;
}

