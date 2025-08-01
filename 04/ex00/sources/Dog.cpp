/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:49:51 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal()
{
    std::cout << "DEFAULT Constructor for Dog 🐶 class called" << std::endl;
    this->type = "Dog";
    return ;
}

Dog::Dog( const Dog& copy ) : Animal()
{
    std::cout << "COPY Constructor for Dog 🐶 class called" << std::endl;
    this->type = copy.type;
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

void    Dog::makeSound( void ) const
{
    std::cout << "🐶 Wooooooooff 🐶" << std::endl;
    return ;
}