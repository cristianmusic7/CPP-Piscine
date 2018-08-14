/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:20:05 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 12:20:07 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
: ClapTrap("FragTrap")
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_max_energy_points = 100;
	this->_energy_points = 100;
	this->_melee_damage = 30;
	this->_range_damage = 20;
	this->_armor = 5;
	this->_level = 1;	
	std::srand(this->_srand);
	std::cout << "FragTrap created!" << std::endl;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_max_energy_points = 100;
	this->_energy_points = 100;
	this->_melee_damage = 30;
	this->_range_damage = 20;
	this->_armor = 5;
	this->_level = 1;	
	std::srand(this->_srand);
	std::cout << "points: " << this->_hit_points << std::endl;
	std::cout << "FragTrap created!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
: ClapTrap(src)
{
	std::cout << "Copy FragTrap created!" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap died!" << std::endl;
}


FragTrap&	FragTrap::operator=(FragTrap const & rhs)
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


void	FragTrap::spitAttack(std::string const & target)
{
	this->_energy_points -= 25;
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " perform " << target << " a spit attack";
	std::cout << ", causing " << this->_melee_damage;
	std::cout << " points of damage !" << std::endl;
}

void	FragTrap::scaryAttack(std::string const & target)
{
	this->_energy_points -= 25;
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " perform " << target << " a scary attack";
	std::cout << ", causing " << this->_melee_damage;
	std::cout << " points of damage !" << std::endl;
}

void	FragTrap::demeaningAttack(std::string const & target)
{
	this->_energy_points -= 25;
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " perform " << target << " a demeaning attack";
	std::cout << ", causing " << this->_melee_damage;
	std::cout << " points of damage !" << std::endl;
}

void	FragTrap::discourageAttack(std::string const & target)
{
	this->_energy_points -= 25;
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " perform " << target << " a discourage attack";
	std::cout << ", causing " << this->_melee_damage;
	std::cout << " points of damage !" << std::endl;
}

void	FragTrap::scornAttack(std::string const & target)
{
	this->_energy_points -= 25;
	std::cout << "FR4G-TP " << this->_name;
	std::cout << " perform " << target << " a melee attack";
	std::cout << ", causing " << this->_melee_damage;
	std::cout << " points of damage !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energy_points >= 25)
	{
		void	(FragTrap::*f[5])(std::string const & target);

		f[0] = &FragTrap::spitAttack;
		f[1] = &FragTrap::scaryAttack;
		f[2] = &FragTrap::demeaningAttack;
		f[3] = &FragTrap::discourageAttack;
		f[4] = &FragTrap::scornAttack;

		std::string attacks[5] = {"spitAttack","scaryAttack","demeaningAttack",
									"discourageAttack","scornAttack"};

		int id = std::rand() % 5;
		(this->*f[id])(target);
	}
	else
		std::cout << "out of energy!" << std::endl;
}

int FragTrap::_srand = std::time(NULL);