/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:20:50 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 12:20:59 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string);
		FragTrap(FragTrap const & src);
		~FragTrap(void);		

		FragTrap&	operator=(FragTrap const & rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);

		void	spitAttack(std::string const & target);
		void	scaryAttack(std::string const & target);
		void	demeaningAttack(std::string const & target);
		void	discourageAttack(std::string const & target);
		void	scornAttack(std::string const & target);

		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vaulthunter_dot_exe(std::string const & target);
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