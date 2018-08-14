/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 00:56:02 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/28 00:56:04 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);		

		Fixed&	operator=(Fixed const & rhs);

		int getRawBits( void ) const; 
		void setRawBits( int const raw );

	private:
		int _fixed_point;

		static const int _fractional_bits;
};

#endif
