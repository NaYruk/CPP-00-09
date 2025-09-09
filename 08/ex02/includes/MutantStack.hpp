/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:58:15 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/09 03:33:57 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    
    public :
    
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        
        // Canonical
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack& copy) : std::stack<T, Container>(copy) {}
        MutantStack& operator=(const MutantStack& copy)
        {
            std::stack<T, Container>::operator=(copy);
            return *this;
        }
        ~MutantStack() {}

        //Iterator, whith the Underlying container of std::stack is a std::deque by default
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
    
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
};