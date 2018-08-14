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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	test("test", 1);
	Bureaucrat	test2("test2", 150);
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;

	ShrubberyCreationForm shrub("tree");
	std::cout << shrub << std::endl;

	shrub.execute(test);

	shrub.beSigned(test);
	test.executeForm(shrub);

	try
	{
		test.executeForm(shrub);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	RobotomyRequestForm robot("Robot");
	std::cout << robot << std::endl;

	robot.execute(test);

	std::cout << std::endl;
	robot.beSigned(test);
	test.executeForm(robot);
	test.executeForm(robot);

	try
	{
		std::cout << std::endl;
		test.executeForm(robot);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	PresidentialPardonForm pres("I Didn't Do It I Swear");
	std::cout << pres << std::endl;

	pres.execute(test);

	pres.beSigned(test);
	test.executeForm(pres);

	try
	{
		test.executeForm(pres);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}