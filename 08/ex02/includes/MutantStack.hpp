/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:58:15 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/15 12:29:51 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
    
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        
        // Canonical
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
        MutantStack& operator=(const MutantStack& copy)
        {
            std::stack<T>::operator=(copy);
            return *this;
        }
        ~MutantStack() {}

        //Iterator, whith the Underlying container of std::stack is a std::deque by default
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
    
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
};