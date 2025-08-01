/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:41:11 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal(), brain(new Brain())
{
    std::cout << "DEFAULT Constructor for Dog 🐶 class called" << std::endl;
    this->type = "Dog";
    return ;
}

Dog::Dog( const Dog& copy ) : Animal()
{
    std::cout << "COPY Constructor for Dog 🐶 class called" << std::endl;
    this->brain = new Brain(*copy.brain);
    this->type = copy.type;
    return ;
}

Dog& Dog::operator=( const Dog& copy )
{
    if (this != &copy)
    {
        delete this->brain;
        this->brain = new Brain(*copy.brain);
        this->type = copy.type;
    }
    return *this;
}

Dog::~Dog( void )
{
    std::cout << "DESTRUCTOR for Dog 🐶 class called" << std::endl;
    delete this->brain;
    return ;
}

void    Dog::makeSound( void ) const
{
    std::cout << "🐶 Wooooooooff 🐶" << std::endl;
    return ;
}

void    Dog::addIdea(const std::string& line)
{
    this->brain->put_ideas(line);
    return ;
}

void    Dog::showIdeas( void ) const
{
    this->brain->explain_ideas();
    return ;
}