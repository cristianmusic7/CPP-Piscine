/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:39:33 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 12:39:34 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

#include <sstream>
#include <string>

Bullet::Bullet(int dmg) : AEntity(0, 0, 1, '|'), _dmg(dmg)
{

	return ;
}

Bullet::Bullet(Bullet const & ref) : AEntity(0, 0, 1, '|')
{
	*this = ref;
	return ;
}

Bullet::~Bullet()
{
	return ;
}

Bullet&			Bullet::operator=(Bullet const & rhs)
{
	AEntity::operator=(rhs);
	this->_dmg = rhs.getDmg();
	return (*this);
}

int			Bullet::getDmg() const
{
	return (this->_dmg);
}

std::string		Bullet::print() const
{
	std::stringstream ss;

	ss << "[Bullet " << this->getSymbol()
		<< " at (" << this->getX() << ", "
		<< this->getY() << ")]";
	return (ss.str());
}

void			Bullet::update()
{
	this->draw(this->_x, this->_y - 1);
}
