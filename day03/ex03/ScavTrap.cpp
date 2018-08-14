/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:38:41 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 15:38:43 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
: ClapTrap("ScavTrap")
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_max_energy_points = 50;
	this->_energy_points = 50;
	this->_melee_damage = 20;
	this->_range_damage = 15;
	this->_armor = 3;
	this->_level = 1;
	std::srand(this->_srand);
	std::cout << "ScavTrap creature created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_max_energy_points = 50;
	this->_energy_points = 50;
	this->_melee_damage = 20;
	this->_range_damage = 15;
	this->_armor = 3;
	this->_level = 1;
	std::srand(this->_srand);
	std::cout << "ScavTrap creature created!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
: ClapTrap(src)
{
	std::cout << "Copy of ScavTrap creature created!" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap died!" << std::endl;
}


ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs)
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

void	ScavTrap::drinkingChallenge(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name;
	std::cout << " invite " << target << " to a drinking challenge";
	std::cout << std::endl;
}

void	ScavTrap::singingChallenge(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name;
	std::cout << " invite " << target << " to a singing challenge";
	std::cout << std::endl;
}

void	ScavTrap::roastChallenge(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name;
	std::cout << " invite " << target << " to a roast challenge";
	std::cout << std::endl;
}

void	ScavTrap::jokeChallenge(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name;
	std::cout << " invite " << target << " to a joke challenge";
	std::cout << std::endl;
}

void	ScavTrap::cryingChallenge(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name;
	std::cout << " invite " << target << " to a crying challenge";
	std::cout << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	void	(ScavTrap::*f[5])(std::string const & target);

	f[0] = &ScavTrap::drinkingChallenge;
	f[1] = &ScavTrap::singingChallenge;
	f[2] = &ScavTrap::roastChallenge;
	f[3] = &ScavTrap::jokeChallenge;
	f[4] = &ScavTrap::cryingChallenge;

	std::string attacks[5] = {"drinkingChallenge","singingChallenge","roastChallenge",
								"jokeChallenge","cryingChallenge"};

	int id = std::rand() % 5;
		(this->*f[id])(target);
}

int ScavTrap::_srand = std::time(NULL);
