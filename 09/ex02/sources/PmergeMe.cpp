/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:11 by marcmilliot       #+#    #+#             */
/*   Updated: 2025/09/30 20:18:27 by mmilliot         ###   ########.fr       */
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
    this->_vecContainer = copy._vecContainer;
    this->_dequeContainer = copy._dequeContainer;
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
    
    printVectorContainer(PRINT_BEFORE); // Print the stack Before Algo
    doFordJohnsonVector(this->_vecContainer);
    printVectorContainer(PRINT_AFTER); // Print the stack After Algo

    gettimeofday(&end, NULL); // End the count of time for Vector container
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

    printDequeContainer(PRINT_BEFORE); // Print the stack Before Algo
    doFordJohnsonDeque(this->_dequeContainer);
    printDequeContainer(PRINT_AFTER); // Print the stack After Algo
    
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
            std::cout << this->_vecContainer[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }
    else if (status == PRINT_AFTER)
    {
        std::cout << "After Vector: ";
        for (size_t i = 0; i < this->_vecContainer.size(); i++) {
            std::cout << GREEN <<  this->_vecContainer[i] << " ";
        }
        std::cout << RESET << std::endl;
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
    std::vector<int> JacobstahlSequence = GetJacobstahlSequenceVector(pendingCount);
    std::vector<int> InsertionOrder;
    size_t i = 3;
    if (JacobstahlSequence.back() > 1)
    {
        for (; i < JacobstahlSequence.size() && JacobstahlSequence[i] < static_cast<int>(pendingCount); i++)
        {
            InsertionOrder.push_back(JacobstahlSequence[i]);
            while (InsertionOrder.back() > JacobstahlSequence[i - 1] + 1)
            {
                InsertionOrder.push_back(InsertionOrder.back() - 1);
            }
        }
    }
    size_t add = 1;
    while (InsertionOrder.size() + 1 < pendingCount)
    {
        InsertionOrder.push_back(JacobstahlSequence.back() + add);
        add++;
    }
    return InsertionOrder;
}

void    PmergeMe::insertBinaryVector(std::vector<int>& vec, int value)
{
    int left = 0;
    int right = vec.size();
    
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
    // Conserv the Odd element
    int OddNbr = NO_ODD;
    if (vecC.size() % 2 != 0) {
        OddNbr = vecC.back();
        vecC.pop_back();
    }
    
    
    // Step 1 : Makes pairs and sort the nbr in pairs : [b, a]  b = lowest, a = highest NBR 
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vecC.size(); i += 2)
    {
        int first = vecC[i];
        int second = vecC[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second)); // Make a pair : [b, a]  b = lowest, a = highest NBR 
    }
    
    
    // Step 2 : New Vectors for stock the highest and lowest nbr in each pairs (b, a) and sort recursivly the biggests numbers
    std::vector<int> largestNumbers;
    std::vector<int> lowestNumbers;

    for (size_t i = 0; i < pairs.size(); i++) {
        largestNumbers.push_back(pairs[i].second);
        lowestNumbers.push_back(pairs[i].first);
    }
    if (largestNumbers.size() > 1)
        doFordJohnsonVector(largestNumbers);
    
        
    // Step 3 : Construct the final chain with the first element of pend (lowestNumbers), add the main(largestNumbers)
    // and insert with the Jacobstahl sequences the rest of pend (lowestNumbers) by binary search if an ODD element exist insert him at last.
    vecC.clear();

    if (lowestNumbers.size() >= 1)
        vecC.push_back(lowestNumbers[0]); // add the first element of pend (lowestNumbers)
    for (size_t i = 0; i < largestNumbers.size(); i++) {
        vecC.push_back(largestNumbers[i]); // add the main(largestNumbers)
    }
    
    if (lowestNumbers.size() > 1)
    {
        size_t pendingCount = lowestNumbers.size() - 1; // - 1 because of the first element of pend is automaticly add.
        std::vector<int> insertionOrder = JacobstahlInsertionOrderVector(pendingCount); // Get the Jacobstahl Insertion Order, if lowestNumbers = 6 : JIO = [3,2,5,4,6]
        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int index = insertionOrder[i];
            insertBinaryVector(vecC, lowestNumbers[index]); // Insert with Binary search the lowestNumber in the final stack, by follow the Jacobstahl sequence
        }
    }
    
    if (OddNbr != NO_ODD)
        insertBinaryVector(vecC, OddNbr); // Insert with Binary search the Odd number if he exist
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
    std::deque<int> JacobstahlSequence = GetJacobstahlSequenceDeque(pendingCount);
    std::deque<int> InsertionOrder;
    size_t i = 3;
    if (JacobstahlSequence.back() > 1)
    {
        for (; i < JacobstahlSequence.size() && JacobstahlSequence[i] < static_cast<int>(pendingCount); i++)
        {
            InsertionOrder.push_back(JacobstahlSequence[i]);
            while (InsertionOrder.back() > JacobstahlSequence[i - 1] + 1)
            {
                InsertionOrder.push_back(InsertionOrder.back() - 1);
            }
        }
    }
    size_t add = 1;
    while (InsertionOrder.size() + 1 < pendingCount)
    {
        InsertionOrder.push_back(JacobstahlSequence.back() + add);
        add++;
    }
    return InsertionOrder;
}

void    PmergeMe::insertBinaryDeque(std::deque<int>& deque, int value)
{
    int left = 0;
    int right = deque.size();
    
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
    // Conserv the Odd element
    int OddNbr = NO_ODD;
    if (dequeC.size() % 2 != 0) {
        OddNbr = dequeC.back();
        dequeC.pop_back();
    }
    
    
    // Step 1 : Makes pairs and sort the nbr in pairs : [b, a]  b = lowest, a = highest NBR 
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < dequeC.size(); i += 2)
    {
        int first = dequeC[i];
        int second = dequeC[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second)); // Make a pair : [b, a]  b = lowest, a = highest NBR 
    }
    
    
    // Step 2 : New Deques for stock the highest and lowest nbr in each pairs (b, a) and sort recursivly the biggests numbers
    std::deque<int> largestNumbers;
    std::deque<int> lowestNumbers;

    for (size_t i = 0; i < pairs.size(); i++) {
        largestNumbers.push_back(pairs[i].second);
        lowestNumbers.push_back(pairs[i].first);
    }
    if (largestNumbers.size() > 1)
        doFordJohnsonDeque(largestNumbers);
    
        
    // Step 3 : Construct the final chain with the first element of pend (lowestNumbers), add the main(largestNumbers)
    // and insert with the Jacobstahl sequences the rest of pend (lowestNumbers) by binary search if an ODD element exist insert him at last.
    dequeC.clear();

    if (lowestNumbers.size() >= 1)
        dequeC.push_back(lowestNumbers[0]); // add the first element of pend (lowestNumbers)
    for (size_t i = 0; i < largestNumbers.size(); i++) {
        dequeC.push_back(largestNumbers[i]); // add the main(largestNumbers)
    }
    
    if (lowestNumbers.size() > 1)
    {
        size_t pendingCount = lowestNumbers.size() - 1; // - 1 because of the first element of pend is automaticly add.
        std::deque<int> insertionOrder = JacobstahlInsertionOrderDeque(pendingCount); // Get the Jacobstahl Insertion Order, if lowestNumbers = 6 : JIO = [3,2,5,4,6]
        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int index = insertionOrder[i];
            insertBinaryDeque(dequeC, lowestNumbers[index]); // Insert with Binary search the lowestNumber in the final stack, by follow the Jacobstahl sequence
        }
    }
    
    if (OddNbr != NO_ODD)
        insertBinaryDeque(dequeC, OddNbr); // Insert with Binary search the Odd number if he exist
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
