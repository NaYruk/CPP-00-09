/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/24 19:16:24 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// ============== CANONICAL ==============
PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( PmergeMe const & copy )
{
    *this = copy;
    return ;
}

PmergeMe &   PmergeMe::operator=( PmergeMe const & copy )
{
    this->vecContainer = copy.vecContainer;
    this->dequeContainer = copy.dequeContainer;
    return *this;
}

PmergeMe::~PmergeMe( void ) {}



// ============= PUBLIC METHODS FOR VECTOR CONTAINER ==============
void    PmergeMe::sortWithVector(char ** toSort)
{
    if (fillVectorContainer(toSort) == -1)
        return ;

    timeval start, end;
    gettimeofday(&start, NULL); // Start the count of time for Vector container

    // Process Algorithm

    gettimeofday(&end, NULL); // End the count of time for Vector container
    printTimeElapsed(start, end, VECTOR_CONTAINER, this->vecContainer.size()); // Print the Time Elapsed between the start / end of the Algorithm
    return;
}

// ============= PUBLIC METHODS FOR DEQUE CONTAINER ==============
void    PmergeMe::sortWithDeque(char ** toSort)
{
    if (fillDequeContainer(toSort) == -1)
        return ;

    timeval start, end;
    gettimeofday(&start, NULL); // Start the count of time for Deque container

    // Process Algorithm

    gettimeofday(&end, NULL); // End the count of time for Deque container
    printTimeElapsed(start, end, DEQUE_CONTAINER, this->dequeContainer.size()); // Print the Time Elapsed between the start / end of the Algorithm
    return;
}





// ============= PRIVATE METHODS FOR VECTOR CONTAINER ===============
int    PmergeMe::fillVectorContainer(char ** toSort)
{
    for (size_t i = 1; toSort[i] != NULL; i++)
    {
        int intArg = std::atoi(toSort[i]);
        if (std::find(this->vecContainer.begin(), this->vecContainer.end(), intArg) != this->vecContainer.end()) {
            std::cerr << RED "Error : duplicate number found : " << intArg << RESET << std::endl;
            return ERROR;
        }
        this->vecContainer.push_back(intArg);
    }
    return SUCCESS;
}

void    PmergeMe::printVectorContainer( void )
{
    std::cout << "VECTOR CONTAINER : ";
    for (size_t i = 0; i < this->vecContainer.size(); i++) {
        std::cout << this->vecContainer[i] << " ";
    }
    std::cout << std::endl;
    return ;
}



// ============= PRIVATE METHODS FOR DEQUE CONTAINER ===============
int    PmergeMe::fillDequeContainer(char ** toSort)
{
    for (size_t i = 1; toSort[i] != NULL; i++)
    {
        int intArg = std::atoi(toSort[i]);
        if (std::find(this->dequeContainer.begin(), this->dequeContainer.end(), intArg) != this->dequeContainer.end()) {
            std::cerr << RED "Error : duplicate number found : " << intArg << RESET << std::endl;
            return ERROR;
        }
        this->dequeContainer.push_back(intArg);
    }
    return SUCCESS;
}

void    PmergeMe::printDequeContainer( void )
{
    std::cout << "DEQUE CONTAINER : "; 
    for (size_t i = 0; i < this->dequeContainer.size(); i++) {
        std::cout << this->dequeContainer[i] << " ";
    }
    std::cout << std::endl;
    return ;
}



// ============= PRIVATE METHODS FOR ALL CONTAINER ===============
void    PmergeMe::printTimeElapsed(timeval start, timeval end, int typeContainer, size_t rangeSort)
{
    long seconds = end.tv_sec - start.tv_sec;
    long ms = end.tv_usec - start.tv_usec;
    double elapsed = seconds + ms * CONVERT_MS_IN_S;

    if (typeContainer == VECTOR_CONTAINER)
        std::cout << "Time to process a range of " << rangeSort << " elements with std::vector<int> : " << elapsed << " s" << std::endl;
    else if (typeContainer == DEQUE_CONTAINER)
        std::cout << "Time to process a range of " << rangeSort << " elements with std::deque<int> : " << elapsed << " s" << std::endl;
    return ;
}