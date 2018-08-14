/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 01:53:35 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/04 01:53:35 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cfloat>
#include <cmath>

int main(int argc, char **argv)
{
	if (argc == 2)
	{	
		std::string value(argv[1]);

		if (value.size() == 1 && (value[0] >= 32 && value[0] <= 126)
						&& !(value[0] >= '0' && value[0] <= '9'))
		{
			std::cout << "char: '" << value[0] << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
		}
		else
		{
			double	num;
			int size = value.size();
			if (size > 1 && value[size - 1] == 'f' && value.substr(1,size).compare("inf"))
				value.resize(value.size() - 1);
			std::stringstream	ss(value);
			ss >> num;
			if (ss.fail() || !ss.eof())
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return (0);
			}

			if (!(num >= 0 && num <= CHAR_MAX))
				std::cout << "char: impossible" << std::endl;
			else if (value[0] >= 32 && value[0] <= 126)
				std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;

			if (!(num >= INT_MIN && num <= INT_MAX) || num != num)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(num) << std::endl;

			if (!(num >= -FLT_MAX && num <= FLT_MAX) && num == num && !std::isinf(num))
				std::cout << "float: impossible" << std::endl;
			else
			{
				std::cout << "float: " << std::fixed << std::setprecision(1);
				std::cout << static_cast<float>(num) << "f" << std::endl;
			}
				
			std::cout << "float: " << std::fixed << std::setprecision(1);
			std::cout << num << std::endl;
		}
	}
	else
		std::cout << "usage: ./convert <string>" << std::endl;
	return (0);
}
