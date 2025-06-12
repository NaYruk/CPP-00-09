#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
    std::cout << std::endl;
    std::cout << "👋 Welcome to the 80s and their 🤖 amazing technology ! 🤖" << std::endl;
    std::cout << "Enjoy With the best PhoneBook ! 📞" << std::endl;
    std::cout << std::endl;
    return;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Goodbye !!! 👋" << std::endl;
    std::cout << std::endl;
    return;
}

void PhoneBook::add_new_contact()
{
    if (this->nbr_contact >= 8)
    {
        if (this->old_contact >= 8)
            this->old_contact = 0;
        this->Contact_Book[this->old_contact].create_new_contact();
        this->old_contact++;
    }
    else
        this->Contact_Book[this->nbr_contact].create_new_contact();
    this->nbr_contact++;

    return;
}

std::string     truncate_string(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0,9);
        str.push_back('.');
    }
    return (str);
}

void    PhoneBook::print_PhoneBook() const
{
    std::cout << " __________ __________ __________ __________ " << std::endl;
    std:: cout << "|" << std::right << std::setw(10) << "index" << "|";
    std::cout << std::right << std::setw(10) << "First Name" << "|";
    std::cout << std::right << std::setw(10) << "Last Name" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << " __________ __________ __________ __________ " << std::endl;
    
    int i = -1;
    while (++i < this->nbr_contact && i < 8)
    {
        std:: cout << "|" << std::right << std::setw(10) << i + 1 << "|";
        std::cout << std::right << std::setw(10) << truncate_string(this->Contact_Book[i].Get_First_Name()) << "|";
        std::cout << std::right << std::setw(10) << truncate_string(this->Contact_Book[i].Get_Last_Name()) << "|";
        std::cout << std::right << std::setw(10) << truncate_string(this->Contact_Book[i].Get_Nickname()) << "|" << std::endl;
    }
    std::cout << " __________ __________ __________ __________ " << std::endl;
    std::cout << std::endl;


    std::string str;
    int nbr;

    while (true)
    {
        std::cout << "👀 What Contact would you want to See ? 👀" << std::endl;
        std::getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << std::endl;
			std::exit(0);
        }
        if (str.compare("1") >= 0 && str.compare("8") <= 0 && str.length() == 1)
        {
            nbr = std::stoi(str);
            if (nbr > this->nbr_contact)
                std::cout << "Contact is not create !!! ❌" << std::endl;
            else
                break;
        }
        else
            std::cout << "Invalid Index !!! ❌" << std::endl;
    }
    std::cout << std::endl;
    nbr = std::stoi(str) - 1;

    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Contact " << str << ":" << std::endl;
    std::cout << "First Name : " << this->Contact_Book[nbr].Get_First_Name() << std::endl;
    std::cout << "Last Name : " << this->Contact_Book[nbr].Get_Last_Name() << std::endl;
    std::cout << "Nickname : " << this->Contact_Book[nbr].Get_Nickname() << std::endl;
    std::cout << "Phone Number : " << this->Contact_Book[nbr].Get_Phone_Number() << std::endl;
    std::cout << "Darkest Secret : " << this->Contact_Book[nbr].Get_Darkest_Secret() << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

void PhoneBook::print_contact() const
{
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "📋 List of all Contacts in the PhoneBook ! 📋" << std::endl;
    std::cout << std::endl;
    if (this->nbr_contact == 0)
    {
        std::cout << "PhoneBook is Empty... ❌" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        return;
    }
    print_PhoneBook();
}

