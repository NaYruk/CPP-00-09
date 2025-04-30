#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook   P_B;
    std::string str;

    while (str.compare("EXIT") != 0)
    {
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "ADD = add new contact, SEARCH = view a contact, EXIT = Quit program" << std::endl << std::endl;
        std::cout << "Write something... : ";
        std::getline(std::cin, str);
        if (str.empty())
            std::cout << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;

        if (str.compare("ADD") == 0)
        {
            P_B.add_new_contact();
        }
        else if (str.compare("SEARCH") == 0)
        {
            P_B.print_contact();
        }
        else if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
    }
    return 0;
}
