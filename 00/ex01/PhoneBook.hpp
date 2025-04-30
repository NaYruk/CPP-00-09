#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void add_new_contact();
        void print_contact() const;

    private:
        Contact Contact_Book[8];
        void    print_PhoneBook() const;
        int     nbr_contact = 0;
        int     old_contact = 0;
};

#endif