/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 00:56:10 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/28 00:56:13 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
}

Fixed::Fixed(int const n)
{
	this->_fixed_point = n << Fixed::_fractional_bits;
}

Fixed::Fixed(float const f)
{
	this->_fixed_point = roundf(f * (1 << Fixed::_fractional_bits));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_point = raw;
}

float	Fixed::toFloat( void ) const
{
	return (this->_fixed_point / (float)(1 << Fixed::_fractional_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->_fixed_point >> Fixed::_fractional_bits);
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	this->_fixed_point = rhs.getRawBits();

	return *this;
}

//Comparison operators overload

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_fixed_point < rhs.getRawBits());
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_fixed_point > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_fixed_point >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_fixed_point <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_fixed_point == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_fixed_point != rhs.getRawBits());
}

//arithmetic operators overload

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

//Increment/decrement operators overload

Fixed&	Fixed::operator++(void)
{
	this->_fixed_point += 1;

	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();

	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();

	return tmp;
}

Fixed&	Fixed::operator--(void)
{
	this->_fixed_point -= 1;

	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed const & Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const & Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const & Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed const & Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const int Fixed::_fractional_bits = 8;