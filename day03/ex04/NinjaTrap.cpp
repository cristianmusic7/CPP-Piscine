/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:38:41 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 15:38:43 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
: ClapTrap("NinjaTrap")
{
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_max_energy_points = 120;
	this->_energy_points = 120;
	this->_melee_damage = 60;
	this->_range_damage = 5;
	this->_armor = 0;
	this->_level = 1;
	std::srand(this->_srand);
	std::cout << "NinjaTrap creature created!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
: ClapTrap(name)
{
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_max_energy_points = 120;
	this->_energy_points = 120;
	this->_melee_damage = 60;
	this->_range_damage = 5;
	this->_armor = 0;
	this->_level = 1;
	std::srand(this->_srand);
	std::cout << "NinjaTrap creature created!" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
: ClapTrap(src)
{
	std::cout << "Copy of NinjaTrap creature created!" << std::endl;
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap died!" << std::endl;
}


NinjaTrap&	NinjaTrap::operator=(NinjaTrap const & rhs)
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

void	NinjaTrap::ninjaShoebox(ClapTrap const & target)
{
	std::cout << "Especial attack ninjaShoebox inflicted to ClapTrap ";
	std::cout << target.getName() <<  std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::cout << "Especial attack ninjaShoebox inflicted to FragTrap ";
	std::cout << target.getName() <<  std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::cout << "Especial attack ninjaShoebox inflicted to NinjaTrap ";
	std::cout << target.getName() <<  std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{
	std::cout << "Especial attack ninjaShoebox inflicted to NinjaTrap ";
	std::cout << target.getName() <<  std::endl;
}

int NinjaTrap::_srand = std::time(NULL);
