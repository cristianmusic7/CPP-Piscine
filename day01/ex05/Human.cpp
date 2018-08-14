/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:57:10 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 14:57:11 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) { }

Human::~Human(void)
{
	std::cout << "Human died." << std::endl;
}

std::string Human::identify(void) const
{
	return this->_brain.identify();
}

const Brain &Human::getBrain(void) const
{
	return (this->_brain);
}