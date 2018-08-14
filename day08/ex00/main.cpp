/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:26:14 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/06 23:14:04 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(int argc, char **argv)
{
	std::srand(std::rand() + clock());

	if (argc == 2)
	{
		std::vector<int> l;

		l.push_back(std::rand() % 5);
		l.push_back(std::rand() % 5);
		l.push_back(std::rand() % 5);
		l.push_back(std::rand() % 5);
		l.push_back(std::rand() % 5);

		std::vector<int>::iterator ptr;

		for (ptr = l.begin(); ptr != l.end(); ptr++)
	        std::cout << *ptr << " ";

	    std::cout << std::endl; 

		try
		{
			int index = easyfind(l, atoi(argv[1]));
			std::cout << index << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "error: " <<  e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
