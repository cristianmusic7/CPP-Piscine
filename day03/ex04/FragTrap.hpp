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

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string);
		FragTrap(FragTrap const & src);
		~FragTrap(void);		

		FragTrap&	operator=(FragTrap const & rhs);

		void	spitAttack(std::string const & target);
		void	scaryAttack(std::string const & target);
		void	demeaningAttack(std::string const & target);
		void	discourageAttack(std::string const & target);
		void	scornAttack(std::string const & target);

		void	vaulthunter_dot_exe(std::string const & target);

	private:
		static int _srand;
};

#endif