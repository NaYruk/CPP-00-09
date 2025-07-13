/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:36:49 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : type("WrongCat")
{
    std::cout << "DEFAULT Constructor for WrongCat 🐈 class called" << std::endl;
    return ;
}

WrongCat::WrongCat( const WrongCat& copy )
{
    std::cout << "COPY Constructor for WrongCat 🐈 class called" << std::endl;
    *this = copy;
    return ;
}

WrongCat& WrongCat::operator=( const WrongCat& copy )
{
    this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "DESTRUCTOR for WrongCat 🐈 class called" << std::endl;
    return ;
}


std::string    WrongCat::getType( void ) const
{
    return this->type;
}

void           WrongCat::makeSound( void ) const
{
    std::cout << "🐈 Miaowwwwwwwww ! 🐈" << std::endl;
    return ;
}