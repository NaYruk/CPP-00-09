/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:49:39 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal()
{
    std::cout << "DEFAULT Constructor for Cat 🐈 class called" << std::endl;
    this->type = "Cat";
    return ;
}

Cat::Cat( const Cat& copy ) : Animal()
{
    std::cout << "COPY Constructor for Cat 🐈 class called" << std::endl;
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
    return ;
}


void           Cat::makeSound( void ) const
{
    std::cout << "🐈 Miaowwwwwwwww ! 🐈" << std::endl;
    return ;
}