/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/30 20:01:43 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <vector>
#include <deque>
#include <sys/time.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// ======== Macro for Magic numbers =========
#define MINIMUM_ARGUMENTS 2
#define VECTOR_CONTAINER 1
#define DEQUE_CONTAINER 2
#define SUCCESS 0
#define ERROR -1
#define NO_ODD -1
#define PRINT_BEFORE 1
#define PRINT_AFTER 2

class PmergeMe
{
    public:
        // ============== CANONICAL ==============
        PmergeMe( void );
        PmergeMe( PmergeMe const & copy );
        PmergeMe & operator=( PmergeMe const & copy );
        ~PmergeMe( void );
        
        // ============= PUBLIC METHODS FOR VECTOR CONTAINER ==============
        void    sortWithVector(char ** toSort);

        // ============= PUBLIC METHODS FOR DEQUE CONTAINER ==============
        void    sortWithDeque(char ** toSort);
    
    private:
        std::vector<int>    _vecContainer;
        std::deque<int>     _dequeContainer;
        bool                _firstSort;

        // ============= PRIVATE METHODS FOR VECTOR CONTAINER ===============
        int                 fillVectorContainer(char ** toSort);
        void                printVectorContainer( int status );
        std::vector<int>    JacobstahlInsertionOrderVector(size_t pendingCount);
        void                insertBinaryVector(std::vector<int>& vec, int value, size_t maxPos);
        void                doFordJohnsonVector( std::vector<int> & vecC );

        // ============= PRIVATE METHODS FOR DEQUE CONTAINER ===============
        int                 fillDequeContainer(char ** toSort);
        void                printDequeContainer( int status );
        std::deque<int>     JacobstahlInsertionOrderDeque(size_t pendingCount);
        void                insertBinaryDeque(std::deque<int>& deque, int value, size_t maxPos);
        void                doFordJohnsonDeque( std::deque<int> & dequeC );

        // ============= PRIVATE METHODS FOR ALL CONTAINER ===============
        void    printTimeElapsed(timeval start, timeval end, int typeContainer, size_t rangeSort);
};