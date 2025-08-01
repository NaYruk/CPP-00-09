/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:50:34 by marcmilliot      ###   ########.fr       */
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
    this->type = copy.type;
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

void Animal::addIdea(const std::string& idea)
{
    std::cout << "Basic Animal has no brain to store ideas!" << std::endl;
    return ;
}

void Animal::showIdeas(void) const
{
    std::cout << "Basic Animal has no ideas to show!" << std::endl;
    return ;
}