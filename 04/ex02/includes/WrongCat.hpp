/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:46:43 by mmilliot          #+#    #+#             */
/*   Updated: 2025/07/13 19:58:13 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./WrongAnimal.hpp"
#include "./Brain.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat( const WrongCat& copy );
        WrongCat& operator=( const WrongCat& copy );
        virtual ~WrongCat( void );

        std::string    getType( void ) const;
        void           makeSound( void ) const;   
    
    private:
        std::string type;
        Brain*      brain;
};