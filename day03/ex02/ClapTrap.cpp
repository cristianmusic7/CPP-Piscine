/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:20:05 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 12:20:07 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
:_name("ClapTrap")
{
	this->_level = 1;
	this->_max_energy_points = 100;
	std::cout << "ClapTrap created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:_name(name)
{
	this->_level = 1;
	this->_max_energy_points = 100;
	std::cout << "ClapTrap created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy ClapTrap created!" << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap died!" << std::endl;
}


ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
{
	this->_energy_points = rhs.getHitPoints();
	this->_max_hit_points = rhs._max_hit_points;
	this->_energy_points = rhs.getEnergyPoints();
	this->_max_energy_points = rhs._max_energy_points;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_melee_damage = rhs._melee_damage;
	this->_range_damage = rhs._range_damage;
	this->_armor = rhs._armor;
	return *this;
}


void	ClapTrap::rangedAttack(std::string const & target)
{
	if ((int)(this->_energy_points - _range_damage >= 0))
	{
		this->_energy_points -= _range_damage;
		std::cout << this->_name;
		std::cout << " attacks " << target << " at range ";
		std::cout << ", causing " << this->_range_damage;
		std::cout << " points of damage !" << std::endl;
	}
	else
		std::cout << " Not enough energy to perform the attack!" << std::endl;	
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if ((int)(this->_energy_points - _melee_damage >= 0))
	{
		this->_energy_points -= _melee_damage;
		std::cout << this->_name;
		std::cout << " perform " << target << " a melee attack";
		std::cout << ", causing " << this->_melee_damage;
		std::cout << " points of damage !" << std::endl;
	}
	else
		std::cout << " Not enough energy to perform the attack!" << std::endl;	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->_hit_points - (amount - this->_armor)) >= 0)
		this->_hit_points -= (amount - this->_armor);
	else
		this->_hit_points = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)(this->_hit_points + amount) <= this->_max_hit_points)
		this->_hit_points += amount;		
	else
		this->_hit_points = this->_max_hit_points;
}

int		ClapTrap::getHitPoints(void) const
{
	return this->_hit_points;
}

int		ClapTrap::getEnergyPoints(void) const
{
	return this->_energy_points;
}