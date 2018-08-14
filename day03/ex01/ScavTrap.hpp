/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:38:48 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 15:38:50 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>

class ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);		

		ScavTrap&	operator=(ScavTrap const & rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);

		void	drinkingChallenge(std::string const & target);
		void	singingChallenge(std::string const & target);
		void	roastChallenge(std::string const & target);
		void	jokeChallenge(std::string const & target);
		void	cryingChallenge(std::string const & target);

		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(std::string const & target);
		int		getHitPoints(void) const;
		int		getEnergyPoints(void) const;

	private:
		int	_hit_points;
		int _max_hit_points;
		int _energy_points;
		int _max_energy_points;
		int _level;
		std::string _name;
		int _melee_damage;
		int _range_damage;;
		int _armor;

		static int _srand;
};

#endif
