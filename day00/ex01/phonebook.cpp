/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 02:30:51 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/26 02:30:52 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> 
#include "Contact.class.hpp"

std::string resize_str(std::string str)
{
	if (str.size() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int proccess_command(std::string command, Contact *contacts, int index)
{
	int c;
	int search_id;
	int valid;

	valid = 1;
	c = 0;	
	if (!command.compare("ADD"))
	{
		if (index >= 8)
			return (1);
		contacts[index].AddData();
	}
	else if (!command.compare("SEARCH"))
	{
		std::cout << "Searching..." << std::endl;
		if (index == 0)
		{
			std::cout << "your phonebook is empty, go get some friends" << std::endl;
			return (1);
		}
		std::cout << "     index|first name| last name|  nickname|" << std::endl;
		while (c < index)
		{
			std::cout << std::setw(10) << c + 1 << std::setfill(' ') << "|";
			std::cout << std::setw(10) << resize_str(contacts[c].getFirstname()) << std::setfill(' ') << "|";
			std::cout << std::setw(10) << resize_str(contacts[c].getLastname()) << std::setfill(' ') << "|";
			std::cout << std::setw(10) << resize_str(contacts[c].getNickname()) << std::setfill(' ') << "|";
			std::cout << std::endl;
			c++;
		}
		std::cout << "Enter contact's index: ";
		std::cin >> search_id;
		while (!std::cin.good() || search_id > index || search_id <= 0)
		{
			if (!std::cin.good())
			{
				std::cin.clear();
            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			}			
			std::cout << "Please enter a valid index (1 - " << index << "): ";
			std::cin >> search_id;
		}
		contacts[search_id - 1].PrintData();
	}
	else if (!command.compare("EXIT"))
	{
		std::cout << "Bye" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "Invalid command: " << command << std::endl;
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	}
	return (1);
}

int		main(void)
{
	std::string command;
	Contact contacts[9];
	int c;

	c = 0;
	std::cout << "Welcome to your phonebook." << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "Enter a command: ";
	std::cin >> command;
	while (proccess_command(command,contacts, c))
	{
		if (!command.compare("ADD"))
		{
			if (c < 8)
				c++;
			else
			{
				std::cout << "No more contacts can be added." << std::endl;
			}
		}
		std::cout << "Enter a command: ";
		std::cin >> command;	
	}
	return (0);
}

