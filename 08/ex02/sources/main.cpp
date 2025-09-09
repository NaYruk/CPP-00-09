/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:58:17 by mmilliot          #+#    #+#             */
/*   Updated: 2025/09/09 03:47:06 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main()
{
    {
        //Subject TEST : Underlying container is Deque
        std::cout << "Subject TEST : Underlying container is Deque\n" << std::endl;
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Print the last nbr push : " << mstack.top() << std::endl;
    
        mstack.pop();
        
        std::cout << "Print the size of the stack : " << mstack.size() << std::endl;
    
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << "Print all stack : " << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    
    {
        //My TESTS : Underlying container is LIST
        std::cout << "\n\nMy TEST : Underlying container is LIST\n" << std::endl;
        MutantStack<char, std::list<char> > mstack;

        mstack.push('a');
        mstack.push('b');

        std::cout << "Print the last nbr push : " << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << "Print the size of the stack : " << mstack.size() << std::endl;

        mstack.push('c');
        mstack.push('d');
        mstack.push('e');
                
        MutantStack<int, std::list<char> >::iterator it = mstack.begin();
        MutantStack<int, std::list<char> >::iterator ite = mstack.end();

        while (it != ite)
        {
            std::cout << "Print all stack : " << *it << std::endl;
            ++it;
        }
    }

    {
        //Compair Precedent test with an std::list classic
        std::cout << "\n\nCompair Precedent test with an std::list classic\n" << std::endl;
        std::list<char> stack;
        
        stack.push_back('a');
        stack.push_back('b');
        
        std::cout << "Print the last nbr push : " << stack.back() << std::endl;

        stack.pop_back();
        
        std::cout << "Print the size of the stack : " << stack.size() << std::endl;

        stack.push_back('c');
        stack.push_back('d');
        stack.push_back('e');

        std::list<char>::iterator it = stack.begin();
        std::list<char>::iterator ite = stack.end();

        while (it != ite)
        {
            std::cout << "Print all stack : " << *it << std::endl;
            ++it;
        }
    }
    
    return 0;
}