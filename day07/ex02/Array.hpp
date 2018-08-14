/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:27:24 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/05 19:27:27 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
# define Array_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
	public:
		Array<T>(void)
		{
			this->_elements = 0;
		}

		Array<T>(unsigned int n)
		{
			this->_elements = new T[n];
			this->_size = n;
		}

		Array<T>(Array const & src)
		{
			this->_elements = new T[src.size()];
			this->_size = src.size();
			for (unsigned int i = 0; i < this->_size; i++)
			{
				this->_elements[i] = src[i];
			}			
		}

		~Array<T>(void)
		{
			if (this->_elements != NULL)
				delete [] this->_elements;
		}

		Array<T> operator=( Array<T> const &rhs )
		{			
			this->_elements = new T[rhs.size()];
			this->_size = rhs.size();
			for (unsigned int i = 0; i < this->_size; i++)
			{
				this->_elements[i] = rhs[i];			
			}
			return *this;
		}

		T &operator[]( unsigned int num ) const
		{
			if (num >= this->_size)
			{
				throw std::exception();
			}
			return this->_elements[num];
		}

		unsigned int size(void) const
		{
			return (this->_size);
		}

	private:
		T				*_elements;
		unsigned int	_size;
};

#endif
