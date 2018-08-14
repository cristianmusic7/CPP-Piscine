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

	std::cout << std::endl << "** Now signing the form with Arta and than executing the form **" << std::endl;
	shrub.beSigned(test);
	test.executeForm(shrub);

	try
	{
		std::cout << std::endl << "** Attempting to execute form with Lydeka which should error **" << std::endl;
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
	std::cout << robot << std::endl << "**Executing form before signing, it will not work **" << std::endl;

	robot.execute(test);

	std::cout << std::endl << "** Now signing the form with Arta and than executing the form 2x **" << std::endl;
	robot.beSigned(test);
	test.executeForm(robot);
	test.executeForm(robot);

	try
	{
		std::cout << std::endl << "** Attempting to execute form with Lydeka which should error **" << std::endl;
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


	std::cout << std::endl << "** Creating Presidential Pardon Form <I Didn't Do It I Swear> **" << std::endl;

	PresidentialPardonForm pres("I Didn't Do It I Swear");
	std::cout << pres << std::endl << "**Executing form before signing, it will not work **" << std::endl;

	pres.execute(test);

	std::cout << std::endl << "** Now signing the form with Arta and than executing the form **" << std::endl;
	pres.beSigned(test);
	test.executeForm(pres);

	try
	{
		std::cout << std::endl << "** Attempting to execute form with Lydeka which should error **" << std::endl;
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