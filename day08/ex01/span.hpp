/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:25:51 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/06 23:23:05 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const & src);
		~Span(void);	

		Span&	operator=(Span const & rhs);

		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);

	private:
		std::vector<int>	_items;
		unsigned int		_size;	
};

#endif

