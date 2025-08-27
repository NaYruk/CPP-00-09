/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:16:42 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/26 14:36:42 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

class	ScalarConverter
{
	public:
		// Method convert
		static void convert( std::string const & literal );
	
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter& copy );
		ScalarConverter& operator=( ScalarConverter& copy );
		~ScalarConverter( void );
};