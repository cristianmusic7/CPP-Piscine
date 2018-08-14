/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 01:05:38 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 01:05:39 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
:_name("Default"),_grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name)
:_name(name),_grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
:_name(name),_grade(grade)
{

}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "You aren't a bureaucrat anymore :D" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}
int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}	
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form & form)
{
	try
	{
		if (this->_grade > form.getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		else
			form.beSigned(*this);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "can't sing it" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		if (this->_grade > form.getExecGrade())
			throw Bureaucrat::GradeTooLowException();
		else
			form.execute(*this);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "can't sing it" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{ 
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & rhs)
{
	*this = rhs;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return;
}

Bureaucrat::GradeTooHighException&	Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &)
{
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error: grade can't be higher");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{ 
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const & rhs)
{
	*this = rhs;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}

Bureaucrat::GradeTooLowException&	Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &)
{
	return (*this);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Error: grade can't be lower");
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}


