#include "Contact.hpp"

Contact::Contact()
{
    return;
}

Contact::~Contact()
{
    return;
}

void Contact::create_new_contact()
{
    std::string str;

    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "📞 Creation of a new Contact ! 📞" << std::endl;
    std::cout << std::endl;
    while (str.empty())
    {
        std::cout << "First Name : ";
        std::getline(std::cin, str);
        this->_First_Name = str;
        std::cout << std::endl;
    }
    str.clear();
    while (str.empty())
    { 
        std::cout << "Last Name : ";
        std::getline(std::cin, str);
        this->_Last_Name = str;
        std::cout << std::endl;
    }
    str.clear();
    while (str.empty())
    { 
        std::cout << "Nickname : ";
        std::getline(std::cin, str);
        this->_Nickname = str;
        std::cout << std::endl;
    }
    str.clear();
    while (str.empty())
    { 
        std::cout << "Phone Number : ";
        std::getline(std::cin, str);
        this->_Phone_Number = str;
        std::cout << std::endl;
    }
    str.clear();
    while (str.empty())
    { 
        std::cout << "Darkest Secret : ";
        std::getline(std::cin, str);
        this->_Darkest_Secret = str;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------------" << std::endl;
    
    return;
}

std::string Contact::Get_First_Name() const
{
    return (_First_Name);
}

std::string Contact::Get_Last_Name() const
{
    return (_Last_Name);
}

std::string Contact::Get_Nickname() const
{
    return (_Nickname);
}

std::string Contact::Get_Phone_Number() const
{
    return (_Phone_Number);
}

std::string Contact::Get_Darkest_Secret() const
{
    return (_Darkest_Secret);
}