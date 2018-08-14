/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:21:07 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 12:21:09 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	FragTrap f("cool hero");
	FragTrap f2(f);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;

	//f2 = f;

	f.rangedAttack("hell raiser");
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;

	
	f.meleeAttack("mutant");
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	f.rangedAttack("despised human");
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	f.rangedAttack("despised human");
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;

	f2.rangedAttack("hell raiser");
	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;
	f2.meleeAttack("mutant");
	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;
	

	std::cout << "Mutant peform a melee attack on you" << std::endl;
	f.takeDamage(30);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	std::cout << "despised human peform a ranged attack on you" << std::endl;
	f.takeDamage(20);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;

	std::cout << "Mutant peform a melee attack on you" << std::endl;
	f.takeDamage(30);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	std::cout << "Mutant peform a melee attack on you" << std::endl;
	f.takeDamage(30);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;

	std::cout << "despised human peform a ranged attack on you" << std::endl;
	f.takeDamage(20);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;

	std::cout << "you got some placebos" << std::endl;
	f.beRepaired(40);
	std::cout << "Hit Points:" << f.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;

	std::cout << "random attack f" << std::endl;
	f.vaulthunter_dot_exe("hell raiser");

	std::cout << "Energy Points:" << f.getEnergyPoints() << std::endl;
	std::cout << "random attack f2" << std::endl;
	f2.vaulthunter_dot_exe("hell raiser");

	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;
	std::cout << "random attack f2" << std::endl;
	f2.vaulthunter_dot_exe("hell raiser");

	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;
	std::cout << "random attack f2" << std::endl;
	f2.vaulthunter_dot_exe("hell raiser");

	std::cout << "f2 Energy Points:" << f2.getEnergyPoints() << std::endl;

	/***********************************/

	ScavTrap scav("new scav");
	ScavTrap scav2(scav);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;

	//scav2 = scav;

	scav.rangedAttack("hell raiser");
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	std::cout << "scav2 Energy Points:" << scav2.getEnergyPoints() << std::endl;

	
	scav.meleeAttack("mutant");
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	scav.rangedAttack("despised human");
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	scav.rangedAttack("despised human");
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;

	scav2.rangedAttack("hell raiser");
	std::cout << "scav2 Energy Points:" << scav2.getEnergyPoints() << std::endl;
	scav2.meleeAttack("mutant");
	std::cout << "f2 Energy Points:" << scav2.getEnergyPoints() << std::endl;
	

	std::cout << "Mutant perform a melee attack on you" << std::endl;
	scav.takeDamage(30);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	std::cout << "despised human perform a ranged attack on you" << std::endl;
	scav.takeDamage(20);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;

	std::cout << "Mutant perform a melee attack on you" << std::endl;
	scav.takeDamage(30);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	std::cout << "Mutant perform a melee attack on you" << std::endl;
	scav.takeDamage(30);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;

	std::cout << "despised human perform a ranged attack on you" << std::endl;
	scav.takeDamage(20);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;

	std::cout << "you got some placebos" << std::endl;
	scav.beRepaired(40);
	std::cout << "Hit Points:" << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	std::cout << "scav2 Energy Points:" << scav2.getEnergyPoints() << std::endl;

	std::cout << "random challenge scav" << std::endl;
	scav.challengeNewcomer("hell raiser");

	std::cout << "Energy Points:" << scav.getEnergyPoints() << std::endl;
	std::cout << "random challenge scav2" << std::endl;
	scav2.challengeNewcomer("pity human");

	std::cout << "scav2 Energy Points:" << scav2.getEnergyPoints() << std::endl;
	std::cout << "random challenge scav2" << std::endl;
	scav2.challengeNewcomer("hell raiser");

	std::cout << "scav2 Energy Points:" << scav2.getEnergyPoints() << std::endl;
	std::cout << "random challenge scav2" << std::endl;
	scav2.challengeNewcomer("another scav");

	std::cout << "scav2 Energy Points:" << scav2.getEnergyPoints() << std::endl;
	return 0;
}