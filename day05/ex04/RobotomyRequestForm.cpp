/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:48:40 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 16:48:42 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: Form("Default target", 72,45)
{ }

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form(target, 72,45)
{ }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{ 
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && (executor.getGrade() <= this->getExecGrade()))
	{
		system("afplay Drilling.mp3 &");
		if (rand() % 2)
			std::cout << this->getName() << " has been has been robotomized successfully." << std::endl;
		else
			std::cout << this->getName() << " sobotomy failuerep" << std::endl;
	}
	else if (!this->getIsSigned())
		std::cout << "is not already signed." << std::endl;
	else
		throw Form::GradeTooLowException();
	return;
}

int RobotomyRequestForm::_srand = std::time(NULL);