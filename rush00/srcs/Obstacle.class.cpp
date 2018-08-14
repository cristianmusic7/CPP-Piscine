/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:56:33 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 19:56:54 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.class.hpp"

Obstacle::Obstacle(int x, int y, int speed) : AEntity(x, y, speed, '*')
{
	return ;
}

Obstacle::Obstacle(Obstacle const & ref)
	: AEntity(ref.getX(), ref.getY(), ref.getSpeed(), '*')
{
	*this = ref;
	return ;
}

Obstacle::~Obstacle()
{
	return ;
}

Obstacle&			Obstacle::operator=(Obstacle const & rhs)
{
	AEntity::operator=(rhs);
	return (*this);
}

void			Obstacle::update()
{
	this->_py = this->_y;
	this->_y = this->_y + this->_speed;
}

Obstacle*			Obstacle::clone() const
{
	return (new Obstacle(*this));
}
