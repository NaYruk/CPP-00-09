/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:41:04 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal(), brain(new Brain())
{
    std::cout << "DEFAULT Constructor for Cat 🐈 class called" << std::endl;
    this->type = "Cat";
    return ;
}

Cat::Cat( const Cat& copy ) : Animal()
{
    std::cout << "COPY Constructor for Cat 🐈 class called" << std::endl;
    this->brain = new Brain(*copy.brain);
    this->type = copy.type;
    return ;
}

Cat& Cat::operator=( const Cat& copy )
{
    if (this != &copy)
    {
        delete this->brain;
        this->brain = new Brain(*copy.brain);
        this->type = copy.type;
    }
    return *this;
}

Cat::~Cat( void )
{
    std::cout << "DESTRUCTOR for Cat 🐈 class called" << std::endl;
    delete this->brain;
    return ;
}

void           Cat::makeSound( void ) const
{
    std::cout << "🐈 Miaowwwwwwwww ! 🐈" << std::endl;
    return ;
}

void    Cat::addIdea(const std::string& line)
{
    this->brain->put_ideas(line);
    return ;
}

void    Cat::showIdeas( void ) const
{
    this->brain->explain_ideas();
    return ;
}