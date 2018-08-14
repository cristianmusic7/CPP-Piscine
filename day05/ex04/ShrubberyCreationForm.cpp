/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:48:20 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 16:48:21 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: Form("Default target", 145,137)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form(target, 145,137)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{ 
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && (executor.getGrade() <= this->getExecGrade()))
	{
		std::ofstream	content(this->getName() + "_shrubbery");

		content << "\
					       \\/ |    |/ 	       \n \
				        \\/ / \\||/  /_/___/_        \n \
				         \\/   |/ \\/                \n \
				    _\\__\\_\\   |  /_____/_          \n \
				           \\  | /          /       \n \
				  __ _-----`  |{,-----------~      \n \
				            \\ }{				   \n \
				             }{{					\n \
				             }}{					\n \
				             {{}					\n \
				       , -=-~{ .-^- _ 				\n \
				             `}						\n \
				              {              ";
		std::cout << std::endl;
		std::cout << "ShrubberyForm executed by " << executor.getName() << std::endl;
	}
	else if (!this->getIsSigned())
		std::cout << "is not already signed." << std::endl;
	else
		throw Form::GradeTooLowException();
	return;
}