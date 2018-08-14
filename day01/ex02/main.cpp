/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 02:13:32 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 02:13:34 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent feasting;
	feasting.setZombieType("Feaster");

	Zombie* z1 = feasting.newZombie("alice");
	z1->announce();

	ZombieEvent cleaning;
	cleaning.setZombieType("Cleaner");

	Zombie* z2 = cleaning.newZombie("bob");
	z2->announce();	

	ZombieEvent killing;
	killing.setZombieType("Killer");

	Zombie* z3 = killing.newZombie("Clementine");
	z3->announce();	

	feasting.randomChump();
	killing.randomChump();
	killing.randomChump();
	cleaning.randomChump();
	cleaning.randomChump();

	delete z1;
	delete z2;
	delete z3;
	return 0;
}
