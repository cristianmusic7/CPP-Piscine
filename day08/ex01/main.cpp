/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:26:14 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/06 23:21:53 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	std::srand(std::rand() + clock());

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(sp);
	sp2.addNumber(9);
	sp2.addNumber(17);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	try
	{
		sp2.addNumber(14);
	}
	catch(std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
