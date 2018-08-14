/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 01:05:38 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 01:05:39 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
:_name("Default"),_sign_grade(50),_exec_grade(100)
{

}

Form::Form(std::string name, int sign_grade, int exec_grade)
:_name(name)
{
	try
	{
		if (sign_grade > 150)
			throw Form::GradeTooLowException();
		else if (sign_grade <= 0)
			throw Form::GradeTooHighException();
		else
			this->_sign_grade = sign_grade;

		if (exec_grade > 150)
			throw Form::GradeTooLowException();
		else if (exec_grade <= 0)
			throw Form::GradeTooHighException();
		else
			this->_exec_grade = exec_grade;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(Form const & src)
{
	*this = src;
	return;
}

Form::~Form(void)
{
	std::cout << "Form deleted" << std::endl;
}

Form&	Form::operator=(Form const & rhs)
{
	this->_name = rhs.getName();
	this->_sign_grade = rhs.getSignGrade();
	this->_exec_grade = rhs.getExecGrade();
	this->_signed = rhs.getIsSigned();
	return *this;
}

std::string Form::getName(void) const
{
	return this->_name;
}

int Form::getSignGrade(void) const
{
	return this->_sign_grade;
}

int Form::getExecGrade(void) const
{
	return this->_exec_grade;
}

bool Form::getIsSigned(void) const
{
	return this->_signed;
}

void Form::beSigned(Bureaucrat& b)
{
	try
	{
		if (b.getGrade() >= this->_sign_grade)
			this->_signed =  true;
		else
			throw Form::GradeTooLowException();
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
}

Form::GradeTooHighException::GradeTooHighException(void)
{ 
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & rhs)
{
	*this = rhs;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return;
}

Form::GradeTooHighException&	Form::GradeTooHighException::operator=(GradeTooHighException const &)
{
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Error: grade can't be higher");
}

Form::GradeTooLowException::GradeTooLowException(void)
{ 
	return;
}

Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const & rhs)
{
	*this = rhs;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}

Form::GradeTooLowException&	Form::GradeTooLowException::operator=(GradeTooLowException const &)
{
	return (*this);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Error: grade can't be lower");
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << rhs.getName() << ", form is ";
	if (!rhs.getIsSigned() )
		o << " not";
	o << " signed ";
	return o;
}


