/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:50:49 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain( void )
{
    std::cout << "DEFAULT constructor of Brain 🧠 class called" << std::endl;
    return ;
}

Brain::Brain( const Brain& copy )
{
    std::cout << "COPY Constructor for Brain class called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    return ;
}

Brain& Brain::operator=( const Brain& copy )
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    return *this;
}

Brain::~Brain( void )
{
    std::cout << "DESTRUCTOR of Brain 🧠 class called" << std::endl;
}

void    Brain::put_ideas( std::string line )
{
    int i = 0;
    
    while (i < 100 && !this->ideas[i].empty())
        i++;
    if (i < 100 && this->ideas[i].empty())
        this->ideas[i] = line;
    if (i == 100)
        std::cout << "I have my brain full, i can't retain anything anymore" << std::endl;
    return ;
}

void    Brain::explain_ideas( void )
{
    int i = 0;
    while (i < 100)
    {
        if (!this->ideas[i].empty())
            std::cout << this->ideas[i] << std::endl;
        i++;
    }
    return ;
}

