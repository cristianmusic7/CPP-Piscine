/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:26:07 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/05 20:26:08 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::srand(std::rand() + clock());
	unsigned int i;

	Array<int> int1 = Array<int>(6);
	std::cout << "initial values:" << std::endl;
	for (i = 0; i < int1.size(); i++)
		std::cout << "int1[" << i << "] = " << int1[i] << std::endl;
	std::cout << "initialized values" << std::endl;
	for (i = 0; i < int1.size(); i++)
	{
		int1[i] = i;
		std::cout << "int1[" << i << "] = " << int1[i] << std::endl;
	}
	try
	{
		int1[1] = 1;
	}
	catch(std::exception &e)
	{
		std::cout << "ERROR" << std::endl;
	}

	Array<int> int2 = Array<int>(int1);
	std::cout << "initial values:" << std::endl;
	for (i = 0; i < int2.size(); i++)
		std::cout << "int2[" << i << "] = " << int2[i] << std::endl;
	std::cout << "changing first one:" << std::endl;
	for (i = 0; i < int1.size(); i++)
		int1[i] *= int1[i];
	std::cout << "- first array" << std::endl;
	for (i = 0; i < int1.size(); i++)
		std::cout << "int1[" << i << "] = " << int1[i] << std::endl;
	std::cout << "- second array -" << std::endl;
	for (i = 0; i < int2.size(); i++)
		std::cout << "intsfd2[" << i << "] = " << int2[i] << std::endl;

	Array<int> int3 = int1;
	std::cout << "initial values:" << std::endl;
	for (i = 0; i < int3.size(); i++)
		std::cout << "int3[" << i << "] = " << int3[i] << std::endl;
	std::cout << "changing first one:" << std::endl;
	for (i = 0; i < int1.size(); i++)
		int1[i] *= int1[i];
	std::cout << "- first array" << std::endl;
	for (i = 0; i < int1.size(); i++)
		std::cout << "int1[" << i << "] = " << int1[i] << std::endl;
	std::cout << "- second array -" << std::endl;
	for (i = 0; i < int3.size(); i++)
		std::cout << "intsfd2[" << i << "] = " << int3[i] << std::endl;


	Array<std::string> str(4);
	std::cout << "initial values:" << std::endl;
	for (i = 0; i < str.size(); i++)
		std::cout << "str[" << i << "] = " << str[i] << std::endl;
	std::cout << "changing first one:" << std::endl;
	for (i = 0; i < str.size(); i++)
		str[i] += "test" + std::to_string(std::rand() % str.size());
	std::cout << "- second array -" << std::endl;
	for (i = 0; i < str.size(); i++)
		std::cout << "str[" << i << "] = " << str[i] << std::endl;
	return 0;
}