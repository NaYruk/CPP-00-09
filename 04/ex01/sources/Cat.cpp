/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 20:34:54 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal(), type("Cat"), brain(new Brain())
{
    std::cout << "DEFAULT Constructor for Cat 🐈 class called" << std::endl;
    return ;
}

Cat::Cat( const Cat& copy ) : Animal()
{
    std::cout << "COPY Constructor for Cat 🐈 class called" << std::endl;
    this->brain = new Brain();
    this->type = copy.type;
    return ;
}

Cat& Cat::operator=( const Cat& copy )
{
    this->type = copy.type;
    return *this;
}

Cat::~Cat( void )
{
    std::cout << "DESTRUCTOR for Cat 🐈 class called" << std::endl;
    delete this->brain;
    return ;
}


std::string    Cat::getType( void ) const
{
    return this->type;
}

void           Cat::makeSound( void ) const
{
    std::cout << "🐈 Miaowwwwwwwww ! 🐈" << std::endl;
    return ;
}