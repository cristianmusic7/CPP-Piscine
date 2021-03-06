/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 02:13:03 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 02:13:04 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie(void)
{
	std::string name;
	std::string names[] = {"Fleshy", "Gutsy", "Meaty", "Corpsey", "Sicky"};

	std::string type;
	std::string types[] = {"Killer", "Dancer", "Christian","Vegan"};

	this->_name = names[std::rand() % 5];
	this->_type = types[std::rand() % 4];
	std::cout << this->_name << " has turned into a ";
	std::cout << this->_type << " Zombie" << std::endl;
}

Zombie::Zombie(std::string name, std::string type)
:_name(name),_type(type)
{
	std::cout << this->_name << " has turned into a ";
	std::cout << this->_type << " Zombie" << std::endl;
}

Zombie::~Zombie(void)
{	
	std::cout << "Zombie " << this->_name << " has been eliminated" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (";
	std::cout << this->_type << ")> Braiiiinssss...." << std::endl;
}

int Zombie::_srand = std::time(NULL);