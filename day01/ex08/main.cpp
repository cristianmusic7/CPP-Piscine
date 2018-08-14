/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:39:58 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 16:40:01 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void)
{
	Human bobo;

	bobo.action("meleeAttack", "petty human");
	bobo.action("rangedAttack", "unfornate human");
	bobo.action("intimidatingShout", "scary human");
	return 0;
}
