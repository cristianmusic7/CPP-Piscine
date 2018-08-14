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
#include "Form.hpp"

int main(void)
{
	Bureaucrat b("robot");
	Bureaucrat b2("thief", 45);
	Bureaucrat b_low("thief", 7);

	Bureaucrat b3(b2);

	Form f("form2", 35, 35);
	std::cout << f << std::endl;
	b_low.signForm(f);
	b.signForm(f);

	std::cout << b << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	b.decrementGrade();
	b3.incrementGrade();

	return (0);
}