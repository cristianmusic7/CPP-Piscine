/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:30:49 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 20:30:51 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{ }

Intern::Intern(Intern const & src)
{
	*this = src;
	return;
}

Intern::~Intern(void)
{}

Intern&	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	std::string lower_name = "";
	for (int i=0; i < (int)name.size(); i++)
		lower_name += std::tolower(name[i]);

	std::cout << lower_name << std::endl;
	if (!lower_name.compare("shrubbery creation"))
	{
		std::cout << "Intern creates " << lower_name << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (!lower_name.compare("robotomy request"))
	{
		std::cout << "Intern creates " << lower_name << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (!lower_name.compare("presidential pardon"))
	{
		std::cout << "Intern creates " << lower_name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
		std::cout << "Intern doesn't know what to do " << lower_name << std::endl;
	return (NULL);
}
