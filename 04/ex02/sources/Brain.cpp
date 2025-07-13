/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 19:51:19 by mmilliot         ###   ########.fr       */
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
    *this = copy;
    return ;
}

Brain& Brain::operator=( const Brain& copy )
{
    this->ideas = copy.ideas;
    return *this;
}

Brain::~Brain( void )
{
    std::cout << "DESTRUCTOR of Brain 🧠 class called" << std::endl;
}

