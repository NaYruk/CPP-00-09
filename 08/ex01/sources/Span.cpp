/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:09:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 22:48:18 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Canonical
Span::Span( void ) : _sizeMax(0) {}

Span::Span( unsigned int N ) : _sizeMax(N) {}

Span::Span( Span const & copy ) : _sizeMax(copy._sizeMax)
{
    this->_VecSpan = copy._VecSpan;
    return ;
}

Span &  Span::operator=( Span const & copy )
{
    this->_VecSpan = copy._VecSpan;
    return *this;
}

Span::~Span( void ) {}




//AddNumber Function : Add a single number to the Span
void    Span::addNumber( int const toAdd )
{
    if (this->_VecSpan.size() > this->_sizeMax)
        throw   std::out_of_range(RED "Maximum Integer in the container is reach !" RESET);
        
    this->_VecSpan.push_back( toAdd );
    return ;
}

//shortestSpan Function : Find out the shortest span(distance) between all the numbers stored !
int     Span::shortestSpan( void ) const
{

}

//longestSpan Function : Find out the longest span(distance) between all the numbers stored !
int     Span::longestSpan( void ) const
{
    
}




void    Span::printSpan( void )
{
    std::vector<int>::const_iterator it = this->_VecSpan.begin();
    std::vector<int>::const_iterator end = this->_VecSpan.end();

    for (; it < end; it++)
        std::cout << *it << std::endl;    
}