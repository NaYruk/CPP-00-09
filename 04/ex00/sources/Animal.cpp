/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:30:37 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal( void ) : type("Default Animal")
{
    std::cout << "DEFAULT Constructor for animal class called" << std::endl;
    return ;
}

Animal::Animal( const Animal& copy )
{
    std::cout << "COPY Constructor for animal class called" << std::endl;
    *this = copy;
    return ;
}

Animal& Animal::operator=( const Animal& copy )
{
    this->type = copy.type;
    return *this;
}

Animal::~Animal( void )
{
    std::cout << "DESTRUCTOR for animal class called" << std::endl;
    return ;
}

std::string    Animal::getType( void ) const
{
    return this->type;
}

void           Animal::makeSound( void ) const
{
    std::cout << "Animal Sound" << std::endl;
    return ;
}