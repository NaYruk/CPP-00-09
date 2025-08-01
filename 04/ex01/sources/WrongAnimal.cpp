/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:32:51 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("Default WrongAnimal")
{
    std::cout << "DEFAULT Constructor for WrongAnimal class called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy )
{
    std::cout << "COPY Constructor for WrongAnimal class called" << std::endl;
    this->type = copy.type;
    return ;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& copy )
{
    this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "DESTRUCTOR for WrongAnimal class called" << std::endl;
    return ;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->type;
}

void           WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal Sound" << std::endl;
    return ;
}