/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:09:23 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/09 04:33:50 by mmilliot         ###   ########.fr       */
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
    if (this->_VecSpan.size() >= this->_sizeMax)
        throw   std::out_of_range(RED "Maximum Integer in the container is reach !" RESET);
        
    this->_VecSpan.push_back( toAdd );
    return ;
}

void    Span::addRange( std::vector<int>::iterator first, std::vector<int>::iterator last )
{
    if (this->_sizeMax < this->_VecSpan.size() + std::distance(first, last))
        throw std::out_of_range(RED "Maximum Integer in the container is reach !" RESET);
    this->_VecSpan.insert(this->_VecSpan.end(), first, last);
    return ;
}

//shortestSpan Function : Find out the shortest span(distance) between all the numbers stored !
int     Span::shortestSpan( void ) const
{
    if (this->_VecSpan.size() <= 1)
        throw   std::runtime_error(RED "Not enough numbers to find a span." RESET);
    
    std::vector<int> sortedVec = this->_VecSpan;
    std::sort(sortedVec.begin(), sortedVec.end());
    
    int shortestSp = std::numeric_limits<int>::max();
    
    for(size_t i = 1; i < sortedVec.size(); ++i) {
        if (shortestSp > (sortedVec[i] - sortedVec[i - 1]))
            shortestSp = sortedVec[i] - sortedVec[i - 1];
    }
    
    return (shortestSp);    
}

//longestSpan Function : Find out the longest span(distance) between all the numbers stored !
int     Span::longestSpan( void ) const
{
    if (this->_VecSpan.size() <= 1)
        throw   std::runtime_error(RED "Not enough numbers to find a span." RESET);

    std::vector<int>::const_iterator it = this->_VecSpan.begin();
    std::vector<int>::const_iterator end = this->_VecSpan.end();

    int shortestNbr = std::numeric_limits<int>::max();
    for(; it < end; it++) {
        if (shortestNbr > *it)
            shortestNbr = *it;
    }
    
    it = this->_VecSpan.begin();

    int largestNbr = std::numeric_limits<int>::min();
    for(; it < end; it++) {
        if (largestNbr < *it)
            largestNbr = *it;
    }
    
    return (largestNbr - shortestNbr);
}




void    Span::printSpan( void )
{
    std::vector<int>::const_iterator it = this->_VecSpan.begin();
    std::vector<int>::const_iterator end = this->_VecSpan.end();

    for (; it < end; it++)
        std::cout << *it << ", ";   
}