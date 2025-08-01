/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcmilliot <marcmilliot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/01 15:10:04 by marcmilliot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <array>

class Brain
{
    public:
        Brain( void ); 
        Brain( const Brain& copy );
        Brain& operator=( const Brain& copy );
        virtual ~Brain( void );

        void        put_ideas(std::string line);
        void        explain_ideas(void);
        
    private:
        std::string ideas[100];
};