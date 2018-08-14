/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 02:13:22 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 02:13:23 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"
#include <ctime>

class ZombieHorde
{
	public:

		ZombieHorde(int n);
		~ZombieHorde(void);

		void setZombieType(std::string type);
		void announce(void);
	private:
		int			_num;
		std::string _type;
		Zombie 		*_zombies;
};

#endif

