/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/24 19:16:00 by mmilliot         ###   ########.fr       */
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
#define CONVERT_MS_IN_S 1e-6
#define SUCCESS 0
#define ERROR -1

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
        std::vector<int>    vecContainer;
        std::deque<int>     dequeContainer;
        
        // ============= PRIVATE METHODS FOR VECTOR CONTAINER ===============
        int     fillVectorContainer(char ** toSort);
        void    printVectorContainer( void );

        // ============= PRIVATE METHODS FOR DEQUE CONTAINER ===============
        int     fillDequeContainer(char ** toSort);
        void    printDequeContainer( void );

        // ============= PRIVATE METHODS FOR ALL CONTAINER ===============
        void    printTimeElapsed(timeval start, timeval end, int typeContainer, size_t rangeSort);
};