/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:30:47 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : type("Dog")
{
    std::cout << "DEFAULT Constructor for Dog 🐶 class called" << std::endl;
    return ;
}

Dog::Dog( const Dog& copy )
{
    std::cout << "COPY Constructor for Dog 🐶 class called" << std::endl;
    *this = copy;
    return ;
}

Dog& Dog::operator=( const Dog& copy )
{
    this->type = copy.type;
    return *this;
}

Dog::~Dog( void )
{
    std::cout << "DESTRUCTOR for Dog 🐶 class called" << std::endl;
    return ;
}

std::string    Dog::getType( void ) const
{
    return this->type;
}

void    Dog::makeSound( void ) const
{
    std::cout << "🐶 Wooooooooff 🐶" << std::endl;
    return ;
}