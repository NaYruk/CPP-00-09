#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class	Account
{
	public:
		Account();					//constructor
		Account(double initial_balance); //constructor with initial balance
		Account (const Account& other);	//constructor of copy
		~Account();				//destructor

		double	get_balance() const;
		void	make_deposit(double deposit);
		void	withdraw_balance(double withdraw);
		void	add_interet(double interet);
	
	private:
		double balance;
};

#endif