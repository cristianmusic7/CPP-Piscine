/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 03:23:30 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 03:23:31 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, std::string mood)
: _name(name), _color(color), _mood(mood)
{
	std::cout << this->_color  << " pony ";
	std::cout << " named \"" << this->_name;
	std::cout << "\" has born";
	std::cout << " and is " << this->_mood;
	std::cout << " about it" << std::endl; 
}
		
Pony::~Pony(void)
{
	std::cout << "You just killed a pony." << std::endl; 
}

void Pony::greet(void) const
{
	std::cout << "Hey there, I'm " << this->_name << std::endl;
	std::cout << "Today I'm really " << this->_mood << std::endl; 
}
