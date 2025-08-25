/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:16:42 by mmilliot          #+#    #+#             */
/*   Updated: 2025/08/25 20:41:21 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	ScalarConverter
{
	public:
		// Method convert
		static void convert( std::string const & literal );
	
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter& const copy );
		ScalarConverter& operator=( ScalarConverter& const copy );
		~ScalarConverter( void );
};