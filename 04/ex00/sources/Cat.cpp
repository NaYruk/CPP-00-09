/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 18:37:08 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : type("Cat")
{
    std::cout << "DEFAULT Constructor for Cat 🐈 class called" << std::endl;
    return ;
}

Cat::Cat( const Cat& copy )
{
    std::cout << "COPY Constructor for Cat 🐈 class called" << std::endl;
    *this = copy;
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