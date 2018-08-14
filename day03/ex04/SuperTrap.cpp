/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:38:41 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 15:38:43 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
: ClapTrap("SuperTrap")
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_max_energy_points = 120;
	this->_energy_points = 120;
	this->_melee_damage = 60;
	this->_range_damage = 20;
	this->_armor = 5;
	this->_level = 1;
	std::srand(this->_srand);
	std::cout << "SuperTrap creature created!" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
: ClapTrap(name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_max_energy_points = 120;
	this->_energy_points = 120;
	this->_melee_damage = 60;
	this->_range_damage = 20;
	this->_armor = 5;
	this->_level = 1;
	std::srand(this->_srand);
	std::cout << "SuperTrap creature created!" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src)
: ClapTrap(src)
{
	std::cout << "Copy of SuperTrap creature created!" << std::endl;
	*this = src;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap died!" << std::endl;
}


SuperTrap&	SuperTrap::operator=(SuperTrap const & rhs)
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

void	SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}

int SuperTrap::_srand = std::time(NULL);
