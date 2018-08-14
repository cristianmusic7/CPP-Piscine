/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:57:00 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 14:57:02 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {}
Brain::~Brain(void) {}


std::string Brain::identify(void) const
{
	const void * address = static_cast<const void*>(this);
	std::stringstream stringStream;
	stringStream << address;  
	std::string str_address = stringStream.str(); 
	return (str_address);
}