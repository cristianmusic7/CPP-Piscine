/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 01:05:48 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 01:05:49 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("robot");
	Bureaucrat b2("thief", 45);

	Bureaucrat b3(b2);


	std::cout << b << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	b.decrementGrade();
	b3.incrementGrade();
	return 0;
}