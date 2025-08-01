/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:49:18 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
    std::cout << "DEFAULT Constructor for WrongCat 🐈 class called" << std::endl;
    this->type = "WrongCat";
    return ;
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal()
{
    std::cout << "COPY Constructor for WrongCat 🐈 class called" << std::endl;
    this->type = copy.type;
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


void           WrongCat::makeSound( void ) const
{
    std::cout << "🐈 Miaowwwwwwwww ! 🐈" << std::endl;
    return ;
}