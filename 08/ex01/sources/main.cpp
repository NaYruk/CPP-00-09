/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:09:20 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/31 22:43:02 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main( void )
{
    Span test(10);

    test.addNumber(42);
    test.addNumber(12);
    
    test.printSpan();
    
    

    return 0;
}