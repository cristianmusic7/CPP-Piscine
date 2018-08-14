/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 11:44:12 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 11:52:29 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.class.hpp"

#include <iostream>
#include <sstream>
#include <string>

AEntity::AEntity(int x, int y, int speed, char symbol)
	: _x(x), _y(y),_px(x), _py(y), _speed(speed), _symbol(symbol)
{
	return ;
}

AEntity::AEntity(AEntity const & ref)
{
	*this = ref;
	return ;
}

AEntity::~AEntity()
{
	return ;
}

AEntity&			AEntity::operator=(AEntity const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_symbol = rhs.getSymbol();
	return (*this);
}

/* Getters/Setters */

int				AEntity::getX() const
{
	return (this->_x);
}

int				AEntity::getY() const
{
	return (this->_y);
}

int				AEntity::getPX() const
{
	return (this->_px);
}

int				AEntity::getPY() const
{
	return (this->_py);
}

int				AEntity::getSpeed() const
{
	return (this->_speed);
}

char				AEntity::getSymbol() const
{
	return (this->_symbol);
}

void				AEntity::setX(int x)
{
	this->_x = x;
	return ;
}

void				AEntity::setY(int y)
{
	this->_y = y;
	return ;
}

void				AEntity::setPX(int x)
{
	this->_px = x;
	return ;
}

void				AEntity::setPY(int y)
{
	this->_py = y;
	return ;
}

void				AEntity::setSpeed(int speed)
{
	this->_speed = speed;
	return ;
}

void				AEntity::setSymbol(char symbol)
{
	this->_symbol = symbol;
	return ;
}

std::string			AEntity::print() const
{
	std::stringstream ss;

	ss << "[Entity " << this->getSymbol()
		<< " at (" << this->getX() << ", "
		<< this->getY() << ")]";
	return (ss.str());
}

/* TODO: Make virtual methods init to 0 in AEntity class */

void				AEntity::onCollision(AEntity * other)
{
	std::cout << this->print()
		<< " collided with "
		<< other->print()
		<< std::endl;
}

void				AEntity::draw() const
{
	std::cout << "Draw/move to ("
		<< this->_x << ", " << this->_y << ")"
		<< std::endl;
}

/* TODO: Boundary check for drawing outside of window */

void				AEntity::draw(int x, int y)
{
	/*std::cout << "Draw/move to ("
		<< x << ", " << y << ")"
		<< std::endl;*/

	this->_px = this->_x;
	this->_py = this->_y;
	this->_x = x;
	this->_y = y;
}

void				AEntity::clear() const
{
	std::cout << "Delete previous characters at "
		<< this->_px << ", " << this->_py << ")"
		<< std::endl;
}

std::ostream	&	operator<<(std::ostream	& o, AEntity const & rhs)
{
	o << rhs.print() << std::endl;

	return (o);
}
