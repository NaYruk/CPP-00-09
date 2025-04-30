#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
    public:
        Contact();
        ~Contact();
        void        create_new_contact();
        std::string Get_First_Name() const;
        std::string Get_Last_Name() const;
        std::string Get_Nickname() const;
        std::string Get_Phone_Number() const;
        std::string Get_Darkest_Secret() const;

    private:
        std::string _First_Name;
        std::string _Last_Name;
        std::string _Nickname;
        std::string _Phone_Number;
        std::string _Darkest_Secret;
};

#endif