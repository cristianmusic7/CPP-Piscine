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

#include "ZombieHorde.hpp"


ZombieHorde::ZombieHorde(int num)
:_num(num)
{
	this->_zombies = new Zombie[num];
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_zombies;
}

void ZombieHorde::setZombieType(std::string type)
{
	this->_type = type;
}
		
void ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_num; ++i)
	{
		this->_zombies[i].announce();
	}
}
