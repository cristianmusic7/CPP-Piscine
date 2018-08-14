/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:48:57 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 16:48:59 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: Form("Default target", 25,5)
{ }

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form(target, 25,5)
{ }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{ 
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && (executor.getGrade() <= this->getExecGrade()))
	{
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else if (!this->getIsSigned())
		std::cout << " is not already signed." << std::endl;
	else
		throw Form::GradeTooLowException();
	return;
}
