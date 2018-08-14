/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:39:51 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 16:39:53 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << "Melle Attack! to " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged Attack! to " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating Attack! to " << target << std::endl;
}


void Human::action(std::string const & action_name, std::string const & target)
{
	void	(Human::*f[3])(std::string const & target);

	f[0] = &Human::meleeAttack;
	f[1] = &Human::rangedAttack;
	f[2] = &Human::intimidatingShout;

	std::string names[3] = {"meleeAttack","rangedAttack","intimidatingShout"};

	for (int i = 0; i < 3; ++i)
	{
		if(!names[i].compare(action_name))
			(this->*f[i])(target);
	}
}