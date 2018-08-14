/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 03:23:37 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 03:23:38 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyLoop(void)
{
	std::string res;

	res = "";
	std::cout << "kill pony? (y/n): ";
	std::getline(std::cin, res);
	while (!res.compare("n") || !res.compare("N"))
	{
		std::cout << "what about now? (y/n): ";
		std::getline(std::cin, res);
	}
	if (res.compare("y") || !res.compare("Y"))
		std::cout << "Invalid option, so: " << std::endl;
	return;
}

void ponyOnTheHeap(std::string name, std::string color, std::string mood)
{
	Pony* pony = new Pony(name,color,mood);
	pony->greet();
	ponyLoop();
	delete pony;
}

void ponyOnTheStack(std::string name, std::string color, std::string mood)
{
	Pony pony(name,color,mood);
	pony.greet();
	ponyLoop();
}

int main(void)
{
	std::string name;
	std::string color;
	std::string mood;

	std::cout << "Creating pony in the heap" << std::endl;
	std::cout << "Pony's name: ";
	std::getline(std::cin, name);
	std::cout << "Pony's color: ";
	std::getline(std::cin, color);
	std::cout << "Pony's mood: ";
	std::getline(std::cin, mood);
	ponyOnTheHeap(name, color, mood);

	std::cout << "Creating pony in the stack" << std::endl;
	std::cout << "Pony's name: ";
	std::getline(std::cin, name);
	std::cout << "Pony's color: ";
	std::getline(std::cin, color);
	std::cout << "Pony's mood: ";
	std::getline(std::cin, mood);
	ponyOnTheStack(name, color, mood);
	
	return 0;
}
