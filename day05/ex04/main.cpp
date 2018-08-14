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
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	Bureaucrat  b1("b1", 78);
	Bureaucrat  b2("b2", 100);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	Intern	i;
	OfficeBlock ob;

	ob.setSigner(b1);
	ob.setExecutor(b2);

	try
	{
		ob.doBureaucracy("Shrubbery Creation", "Bushes");
	}
	catch (OfficeBlock::NoInternException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecuterException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	ob.setIntern(i);
	try
	{
		ob.doBureaucracy("Shrubbery Creation", "Bushes");
	}
	catch (OfficeBlock::NoInternException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecuterException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return(0);

}