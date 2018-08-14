/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rect.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:28:27 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 20:28:29 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rect.class.hpp"

Rect::Rect(int offset_x, int offset_y, int bounds_x, int bounds_y)
	: _offset_x(offset_x), _offset_y(offset_y),
	_bounds_x(bounds_x), _bounds_y(bounds_y)
{
	return ;
}

Rect::~Rect()
{
	return ;
}

Rect::Rect(Rect const & ref)
{
	*this = ref;
	return ;
}

Rect&		Rect::operator=(Rect const & rhs)
{
	this->_offset_x = rhs.getOffsetX();
	this->_offset_y = rhs.getOffsetY();
	this->_bounds_x = rhs.getBoundsX();
	this->_bounds_y = rhs.getBoundsY();
	return (*this);
}

int		Rect::getOffsetX() const
{
	return (this->_offset_x);
}

int		Rect::getOffsetY() const
{
	return (this->_offset_y);
}

int		Rect::getBoundsX() const
{
	return (this->_bounds_x);
}

int		Rect::getBoundsY() const
{
	return (this->_bounds_y);
}

int		Rect::top() const
{
	return (this->_offset_y);
}

int		Rect::bot() const
{
	return (this->_bounds_y - this->_offset_y);
}

int		Rect::left() const
{
	return (this->_offset_x);
}

int		Rect::right() const
{
	return (this->_bounds_x - this->_offset_x);
}

int		Rect::width() const
{
	return (this->_bounds_x - 2 * this->_offset_x);
}

int		Rect::height() const
{
	return (this->_bounds_y - 2 * this->_offset_y);
}
