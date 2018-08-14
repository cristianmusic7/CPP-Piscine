/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:38:48 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/29 15:38:50 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap(void);		

		NinjaTrap&	operator=(NinjaTrap const & rhs);

		void	ninjaShoebox(ClapTrap const & target);
		void	ninjaShoebox(FragTrap const & target);
		void	ninjaShoebox(ScavTrap const & target);
		void	ninjaShoebox(NinjaTrap const & target);

		static int _srand;
};

#endif
