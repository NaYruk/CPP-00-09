/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:01:54 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/28 19:33:57 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Data.hpp"
#include <stdint.h>

class   Serializer
{
    public:
        static uintptr_t    serialize( Data* ptr );
        static Data*        deserialize( uintptr_t raw );

    private:
        Serializer( void );
        Serializer( Serializer const & copy );
        Serializer& operator=( Serializer const & copy );
        ~Serializer( void );
};