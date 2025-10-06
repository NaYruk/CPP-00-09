/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/10/06 20:13:26 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// ============== CANONICAL ==============
PmergeMe::PmergeMe( void ) : _firstSort(true) {}

PmergeMe::PmergeMe( PmergeMe const & copy )
{
    *this = copy;
    return ;
}

PmergeMe &   PmergeMe::operator=( PmergeMe const & copy )
{
    this->_vecContainer = copy._vecContainer;
    this->_dequeContainer = copy._dequeContainer;
    this->_firstSort = copy._firstSort;
    return *this;
}

PmergeMe::~PmergeMe( void ) {}



// ============= PUBLIC METHODS FOR VECTOR CONTAINER ==============
void    PmergeMe::sortWithVector(char ** toSort)
{
    if (fillVectorContainer(toSort) == -1)
        return ;

    timeval start, end;

    if (_firstSort)
        printVectorContainer(PRINT_BEFORE); // Print the stack Before Algo

    gettimeofday(&start, NULL); // Start the count of time for Vector container
    doFordJohnsonVector(this->_vecContainer);
    gettimeofday(&end, NULL); // End the count of time for Vector container

    if (_firstSort) {
        printVectorContainer(PRINT_AFTER); // Print the stack After Algo
        _firstSort = false;
    }

    printTimeElapsed(start, end, VECTOR_CONTAINER, this->_vecContainer.size()); // Print the Time Elapsed between the start / end of the Algorithm
    return;
}

// ============= PUBLIC METHODS FOR DEQUE CONTAINER ==============
void    PmergeMe::sortWithDeque(char ** toSort)
{
    if (fillDequeContainer(toSort) == -1)
        return ;

    timeval start, end;
    gettimeofday(&start, NULL); // Start the count of time for Deque container
    doFordJohnsonDeque(this->_dequeContainer);
    gettimeofday(&end, NULL); // End the count of time for Deque container

    printTimeElapsed(start, end, DEQUE_CONTAINER, this->_dequeContainer.size()); // Print the Time Elapsed between the start / end of the Algorithm
    return;
}





// ============= PRIVATE METHODS FOR VECTOR CONTAINER ===============
int    PmergeMe::fillVectorContainer(char ** toSort)
{
    for (size_t i = 1; toSort[i] != NULL; i++)
    {
        int intArg = std::atoi(toSort[i]);
        if (std::find(this->_vecContainer.begin(), this->_vecContainer.end(), intArg) != this->_vecContainer.end()) {
            std::cerr << RED "Error : duplicate number found : " << intArg << RESET << std::endl;
            return ERROR;
        }
        this->_vecContainer.push_back(intArg);
    }
    return SUCCESS;
}

void    PmergeMe::printVectorContainer( int status )
{
    if (status == PRINT_BEFORE)
    {
        std::cout << "Before: ";
        for (size_t i = 0; i < this->_vecContainer.size(); i++) {
            std::cout << this->_vecContainer[i];
            if (i < this->_vecContainer.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    else if (status == PRINT_AFTER)
    {
        std::cout << "After:  ";
        for (size_t i = 0; i < this->_vecContainer.size(); i++) {
            std::cout << this->_vecContainer[i];
            if (i < this->_vecContainer.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return ;
}

static std::vector<int> GetJacobstahlSequenceVector(size_t pendingCount)
{
    std::vector<int> JacobstahlSequence;
    JacobstahlSequence.push_back(0);
    JacobstahlSequence.push_back(1);
    JacobstahlSequence.push_back(1);
    while (1)
    {
        size_t n = JacobstahlSequence.size();
        size_t result = JacobstahlSequence[n - 1] + (2 * (JacobstahlSequence[n - 2]));
        if (result > pendingCount)
            break;
        else
            JacobstahlSequence.push_back(result);
    }
    return JacobstahlSequence;
}

std::vector<int>    PmergeMe::JacobstahlInsertionOrderVector(size_t pendingCount)
{
    if (pendingCount == 0)
        return std::vector<int>();

    std::vector<int> JacobstahlSequence = GetJacobstahlSequenceVector(pendingCount);
    std::vector<int> InsertionOrder;
    std::vector<bool> inserted(pendingCount, false);

    size_t i = 3;
    // Add Jacobsthal numbers and fill gaps between them
    while (i < JacobstahlSequence.size() && static_cast<size_t>(JacobstahlSequence[i]) < pendingCount)
    {
        size_t jacobsthalIdx = JacobstahlSequence[i];
        size_t prevJacobsthalIdx = JacobstahlSequence[i - 1];

        // Insert from jacobsthalIdx down to prevJacobsthalIdx + 1
        for (size_t idx = jacobsthalIdx; idx > prevJacobsthalIdx; idx--)
        {
            if (!inserted[idx]) {
                InsertionOrder.push_back(idx);
                inserted[idx] = true;
            }
        }
        i++;
    }

    // Fill any remaining indices not yet inserted
    for (size_t idx = 0; idx < pendingCount; idx++)
    {
        if (!inserted[idx])
            InsertionOrder.push_back(idx);
    }

    return InsertionOrder;
}

void    PmergeMe::insertBinaryVector(std::vector<int>& vec, int value, size_t maxPos)
{
    int left = 0;
    int right = maxPos;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    vec.insert(vec.begin() + left, value);
}

void    PmergeMe::doFordJohnsonVector( std::vector<int> & vecC )
{
    if (vecC.size() <= 1)
        return;

    // Conserv the Odd element
    int OddNbr = NO_ODD;
    if (vecC.size() % 2 != 0) {
        OddNbr = vecC.back();
        vecC.pop_back();
    }

    // Step 1 : Makes pairs and sort the nbr in pairs : [smaller, larger]
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vecC.size(); i += 2)
    {
        int first = vecC[i];
        int second = vecC[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    // Step 2 : Recursively sort by larger elements
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].second);
    }

    if (largerElements.size() > 1)
        doFordJohnsonVector(largerElements);

    // Reorder pairs to match sorted larger elements
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == largerElements[i]) {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    pairs = sortedPairs;

    // Step 3 : Build result - start with first smaller element and all larger elements (sorted)
    vecC.clear();
    vecC.push_back(pairs[0].first);
    for (size_t i = 0; i < largerElements.size(); i++) {
        vecC.push_back(largerElements[i]);
    }

    // Step 4 : Insert remaining smaller elements using Jacobsthal order
    if (pairs.size() > 1)
    {
        std::vector<int> jacobsthalOrder = JacobstahlInsertionOrderVector(pairs.size() - 1);
        for (size_t i = 0; i < jacobsthalOrder.size(); i++)
        {
            size_t pairIndex = jacobsthalOrder[i];
            int valueToInsert = pairs[pairIndex + 1].first;

            // Find the position of the corresponding larger element
            size_t maxSearchPos = 0;
            for (size_t j = 0; j < vecC.size(); j++) {
                if (vecC[j] == pairs[pairIndex + 1].second) {
                    maxSearchPos = j + 1;
                    break;
                }
            }
            insertBinaryVector(vecC, valueToInsert, maxSearchPos);
        }
    }

    if (OddNbr != NO_ODD)
        insertBinaryVector(vecC, OddNbr, vecC.size());
    return ;
}








// ============= PRIVATE METHODS FOR DEQUE CONTAINER ===============
int    PmergeMe::fillDequeContainer(char ** toSort)
{
    for (size_t i = 1; toSort[i] != NULL; i++)
    {
        int intArg = std::atoi(toSort[i]);
        if (std::find(this->_dequeContainer.begin(), this->_dequeContainer.end(), intArg) != this->_dequeContainer.end()) {
            std::cerr << RED "Error : duplicate number found : " << intArg << RESET << std::endl;
            return ERROR;
        }
        this->_dequeContainer.push_back(intArg);
    }
    return SUCCESS;
}

void    PmergeMe::printDequeContainer( int status )
{
    if (status == PRINT_BEFORE)
    {
        std::cout << "Before: ";
        for (size_t i = 0; i < this->_dequeContainer.size(); i++) {
            std::cout << this->_dequeContainer[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }
    else if (status == PRINT_AFTER)
    {
        std::cout << "After Deque: ";
        for (size_t i = 0; i < this->_dequeContainer.size(); i++) {
            std::cout << GREEN << this->_dequeContainer[i] << " ";
        }
        std::cout << RESET << std::endl;
    }
    return ;
}

static std::deque<int> GetJacobstahlSequenceDeque(size_t pendingCount)
{
    std::deque<int> JacobstahlSequence;
    JacobstahlSequence.push_back(0);
    JacobstahlSequence.push_back(1);
    JacobstahlSequence.push_back(1);
    while (1)
    {
        size_t n = JacobstahlSequence.size();
        size_t result = JacobstahlSequence[n - 1] + (2 * (JacobstahlSequence[n - 2]));
        if (result > pendingCount)
            break;
        else
            JacobstahlSequence.push_back(result);
    }
    return JacobstahlSequence;
}

std::deque<int>    PmergeMe::JacobstahlInsertionOrderDeque(size_t pendingCount)
{
    if (pendingCount == 0)
        return std::deque<int>();

    std::deque<int> JacobstahlSequence = GetJacobstahlSequenceDeque(pendingCount);
    std::deque<int> InsertionOrder;
    std::vector<bool> inserted(pendingCount, false);

    size_t i = 3;
    // Add Jacobsthal numbers and fill gaps between them
    while (i < JacobstahlSequence.size() && static_cast<size_t>(JacobstahlSequence[i]) < pendingCount)
    {
        size_t jacobsthalIdx = JacobstahlSequence[i];
        size_t prevJacobsthalIdx = JacobstahlSequence[i - 1];

        // Insert from jacobsthalIdx down to prevJacobsthalIdx + 1
        for (size_t idx = jacobsthalIdx; idx > prevJacobsthalIdx; idx--)
        {
            if (!inserted[idx]) {
                InsertionOrder.push_back(idx);
                inserted[idx] = true;
            }
        }
        i++;
    }

    // Fill any remaining indices not yet inserted
    for (size_t idx = 0; idx < pendingCount; idx++)
    {
        if (!inserted[idx])
            InsertionOrder.push_back(idx);
    }

    return InsertionOrder;
}

void    PmergeMe::insertBinaryDeque(std::deque<int>& deque, int value, size_t maxPos)
{
    int left = 0;
    int right = maxPos;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (deque[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    deque.insert(deque.begin() + left, value);
}

void    PmergeMe::doFordJohnsonDeque( std::deque<int> & dequeC )
{
    if (dequeC.size() <= 1)
        return;

    // Conserv the Odd element
    int OddNbr = NO_ODD;
    if (dequeC.size() % 2 != 0) {
        OddNbr = dequeC.back();
        dequeC.pop_back();
    }

    // Step 1 : Makes pairs and sort the nbr in pairs : [smaller, larger]
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < dequeC.size(); i += 2)
    {
        int first = dequeC[i];
        int second = dequeC[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    // Step 2 : Recursively sort by larger elements
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].second);
    }

    if (largerElements.size() > 1)
        doFordJohnsonDeque(largerElements);

    // Reorder pairs to match sorted larger elements
    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == largerElements[i]) {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    pairs = sortedPairs;

    // Step 3 : Build result - start with first smaller element and all larger elements (sorted)
    dequeC.clear();
    dequeC.push_back(pairs[0].first);
    for (size_t i = 0; i < largerElements.size(); i++) {
        dequeC.push_back(largerElements[i]);
    }

    // Step 4 : Insert remaining smaller elements using Jacobsthal order
    if (pairs.size() > 1)
    {
        std::deque<int> jacobsthalOrder = JacobstahlInsertionOrderDeque(pairs.size() - 1);
        for (size_t i = 0; i < jacobsthalOrder.size(); i++)
        {
            size_t pairIndex = jacobsthalOrder[i];
            int valueToInsert = pairs[pairIndex + 1].first;

            // Find the position of the corresponding larger element
            size_t maxSearchPos = 0;
            for (size_t j = 0; j < dequeC.size(); j++) {
                if (dequeC[j] == pairs[pairIndex + 1].second) {
                    maxSearchPos = j + 1;
                    break;
                }
            }

            insertBinaryDeque(dequeC, valueToInsert, maxSearchPos);
        }
    }

    if (OddNbr != NO_ODD)
        insertBinaryDeque(dequeC, OddNbr, dequeC.size());
    return ;
}



// ============= PRIVATE METHODS FOR ALL CONTAINER ===============
void    PmergeMe::printTimeElapsed(timeval start, timeval end, int typeContainer, size_t rangeSort)
{
    long seconds = end.tv_sec - start.tv_sec;
    long ms = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000.0 + ms / 1000.0;

    if (typeContainer == VECTOR_CONTAINER)
        std::cout << "Time to process a range of " << rangeSort << " elements with std::vector<int> : " << elapsed << " ms" << std::endl;
    else if (typeContainer == DEQUE_CONTAINER)
        std::cout << "Time to process a range of " << rangeSort << " elements with std::deque<int> : " << elapsed << " ms" << std::endl;
    return ;
}
