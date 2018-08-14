/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:26:14 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/06 14:26:17 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>

Span::Span(void)
:_size(0)
{ }

Span::Span(unsigned int n)
:_size(n)
{}

Span::Span(Span const & src)
{
	this->_items = src._items;
	this->_size = src._size;
	return;
}

Span::~Span(void)
{ }


Span&	Span::operator=(Span const & rhs)
{
	this->_items = rhs._items;
	this->_size = rhs._size;
	return *this;
}

void Span::addNumber(int num)
{
	if (this->_items.size() + 1 <= this->_size)
		this->_items.push_back(num);
	else
		throw std::exception();
}

int Span::longestSpan(void)
{
	if (this->_size || this->_items.size() > 1)
	{
		std::vector<int> ordered = this->_items;
		std::sort (ordered.begin(), ordered.end());
		return (ordered.back() - ordered.front());
	}
	throw std::exception();
}

int Span::shortestSpan(void)
{
	if (this->_size || this->_items.size() > 1)
	{
		std::vector<int> ordered = this->_items;
		std::sort (ordered.begin(), ordered.end());
		std::vector<int>::iterator ptr;
		int min = this->longestSpan();
		for (ptr = ordered.begin(); ptr != ordered.end() - 1; ptr++)
	    {
	    	if (min > (*(ptr + 1)) - *ptr)
	    		min = *(ptr + 1) - *ptr;
	    }
		return (min);
	}
	throw std::exception();
}
