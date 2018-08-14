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

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include "Zombie.hpp"
#include <ctime>

class ZombieEvent
{
	public:
		void setZombieType(std::string type);
		Zombie* newZombie(std::string name);
		void randomChump(void);
	private:
		std::string _type;

		static int _srand;
};

#endif

