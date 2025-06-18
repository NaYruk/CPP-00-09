/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:56:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/18 10:02:22 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


void	replace_string_one(const std::string str_one, const std::string str_two, std::string &line)
{
	std::string first_part;
	std::string second_part;
	
	std::size_t pos = 0;
	while ((pos = line.find(str_one, pos)) != std::string::npos)
	{
		first_part = line.substr(0, pos);
		second_part = line.substr(pos + str_one.length(), line.length() - (pos + str_one.length()));

		pos += str_two.length();
		line = first_part + str_two + second_part;
	}
	return ;
}



int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << "Parameters is incorrect : [Filename] [s1] [s2]" << std:: endl, 0);

	const std::string filename = argv[1];
	const std::string string_one = argv[2];
	const std::string string_two = argv[3];
	
	if (string_one.empty())
		return (std::cerr << "The String to replace cant be empty !" << std::endl, 0);

	std::ifstream file_in (filename, std::ios::in);
	if (file_in.is_open() == false)
		return ((std::cerr << "The Filename cant be open !" << std::endl), 0);

	std::ofstream file_out (filename + ".replace", std::ios::out | std::ios::app);
	if (file_out.is_open() == false)
		return (file_in.close(), std::cerr << "The Replacing file cant be open !" << std::endl, 0);

	std::string line;
	while (std::getline(file_in, line))
	{
		if (string_one != string_two)
			replace_string_one(string_one, string_two, line);
		if (!file_in.eof())
			file_out << line << std::endl;
		else
			file_out << line;
	}

	file_in.close();
	file_out.close();
	return 0;
}