/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:15:07 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 13:44:31 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
class Array 
{
    public:
        //Canonical !
        //Constructor with no parameters
        Array( void ) : _array( NULL ), _size(0) {};

        //Constructor with an unsigned int n as parameter
        
        Array( unsigned int n ) : _array( new T[n]() ), _size(n) {}
        
        //Constructor of copy with a deep copy of the original array
        Array( Array const & copy ) : _array( new T[copy._size]() ), _size(copy._size) {
            for (unsigned int i = 0; i < copy._size; i++)
                this->_array[i] = copy._array[i];
        }
        
        //Overload of the operator = with a deep copy of the original array
        Array & operator=( Array const & copy ) {
            if (this != &copy)
            {
                if (this->_array)
                    delete[] this->_array;
                    
                this->_array = new T[copy._size]();
                for (unsigned int i = 0; i < copy._size; i++) {
                    this->_array[i] = copy._array[i];
                }
            }
            return *this;
        }

        //Destructor
        ~Array( void ) {
            if (this->_array)
                delete[] this->_array;
            return ;  
        }




        
        //Overload of the [] operator, throw an exception if the index is out of the array
        T & operator[]( unsigned int i ) {
            if (i >= this->_size)
                throw std::out_of_range( RED "Index is out of the array !" RESET );
            else
                return this->_array[i];
        }
        


        
        // Size : Member Function who return the size of the array
        unsigned int size( void ) const {
            return this->_size;
        };




        //Function for Tests, Assign the value of the tab
        void    assign(unsigned int index, T value) {
            (*this)[index] = value;
            return ;
        }

        //Function for Tests, Return the value of the tab for print
        T & print(unsigned int index) {
            return (*this)[index];
        }

    private:
        T * _array;
        unsigned int    _size;
};