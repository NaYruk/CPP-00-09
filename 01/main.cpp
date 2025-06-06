#include "Account.hpp"

int	main()
{
	Account	acc1(3000);
	Account acc2;
	Account acc3(1500);

	std::cout << "Account 1 (3000 at start) : " << acc1.get_balance() << std::endl;
	std::cout << "Account 2 (0 at start) : " << acc2.get_balance() << std::endl;
	std::cout << "Account 3 (1500 at start) : " << acc3.get_balance() << std::endl;

	std::cout << "MAKE DEPOSIT 1000 !" << std::endl;
	acc1.make_deposit(1000);
	acc2.make_deposit(1000);
	acc3.make_deposit(1000);

	std::cout << "Account 1 (3000 at start + depo) : " << acc1.get_balance() << std::endl;
	std::cout << "Account 2 (0 at start + depo) : " << acc2.get_balance() << std::endl;
	std::cout << "Account 3 (1500 at start + depo) : " << acc3.get_balance() << std::endl;

	std::cout << "MAKE WITHDRAW 1000 !" << std::endl;
	acc1.withdraw_balance(1000);
	acc2.withdraw_balance(1000);
	acc3.withdraw_balance(1000);

	std::cout << "Account 1 (3000 at start) : " << acc1.get_balance() << std::endl;
	std::cout << "Account 2 (0 at start) : " << acc2.get_balance() << std::endl;
	std::cout << "Account 3 (1500 at start) : " << acc3.get_balance() << std::endl;

	std::cout << "ADD INTERET 50 !" << std::endl;
	acc1.add_interet(50);
	acc2.add_interet(50);
	acc3.add_interet(50);

	std::cout << "Account 1 (3000 at start) : " << acc1.get_balance() << std::endl;
	std::cout << "Account 2 (0 at start) : " << acc2.get_balance() << std::endl;
	std::cout << "Account 3 (1500 at start) : " << acc3.get_balance() << std::endl;
	return 0;
}