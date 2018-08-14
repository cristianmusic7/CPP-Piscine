/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 02:13:13 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 02:13:15 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name, this->_type);
	return zombie;
}
		
void ZombieEvent::randomChump(void)
{
	std::string names[] = {"Fleshy", "Gutsy", "Meaty", "Corpsey", "Sicky"};
	std::string name = names[std::rand() % 5];
	Zombie zombie(name, this->_type);
	zombie.announce();
}

int ZombieEvent::_srand = std::time(NULL);
