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

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap&	operator=(ScavTrap const & rhs);

		void	drinkingChallenge(std::string const & target);
		void	singingChallenge(std::string const & target);
		void	roastChallenge(std::string const & target);
		void	jokeChallenge(std::string const & target);
		void	cryingChallenge(std::string const & target);

		void	challengeNewcomer(std::string const & target);

		static int _srand;
};

#endif
