/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:30:49 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 20:30:51 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void)
:_intern(NULL),_bureau_signer(NULL),_bureau_executer(NULL)
{ }

OfficeBlock::OfficeBlock(Intern &i, Bureaucrat &sb, Bureaucrat &eb)
:_intern(&i),_bureau_signer(&sb),_bureau_executer(&eb)
{ }

OfficeBlock::~OfficeBlock(void)
{}

OfficeBlock&	OfficeBlock::operator=(OfficeBlock const & rhs)
{
	(void)rhs;
	return (*this);
}


void			OfficeBlock::doBureaucracy(std::string name, std::string target)
{	
	if (!this->_intern)
	{	
		throw OfficeBlock::NoInternException();
		return;
	}
	if (!this->_bureau_signer)
	{	
		throw OfficeBlock::NoSignerException();
		return;
	}
	if (!this->_bureau_executer)
	{	
		throw OfficeBlock::NoExecuterException();
		return;
	}
	Form *form = this->_intern->makeForm(name, target);

	this->_bureau_executer->executeForm(*form);

	delete form;
	return;
}

void			OfficeBlock::setIntern(Intern &i)
{
	this->_intern = &i;
}

void			OfficeBlock::setSigner(Bureaucrat &sb)
{
	this->_bureau_signer = &sb;
}

void			OfficeBlock::setExecutor(Bureaucrat &se)
{
	this->_bureau_executer = &se;
}


OfficeBlock::NoInternException::NoInternException(void)
{
	return;
}

OfficeBlock::NoInternException::NoInternException(NoInternException const &i)
{
	*this = i;
	return;
}

OfficeBlock::NoInternException::~NoInternException(void) throw()
{
	return;
}

OfficeBlock::NoInternException &OfficeBlock::NoInternException::operator=(NoInternException const &rhs) 
{
	(void)rhs;
	return (*this);
}

const char* OfficeBlock::NoInternException::what() const throw()
{
	return ("No interns in the office");
}

OfficeBlock::NoSignerException::NoSignerException(void)
{
	return;
}

OfficeBlock::NoSignerException::NoSignerException(NoSignerException const &sb)
{
	*this = sb;
	return;
}

OfficeBlock::NoSignerException::~NoSignerException(void) throw()
{
	return;
}

OfficeBlock::NoSignerException &OfficeBlock::NoSignerException::operator=(NoSignerException const &rhs) 
{
	(void)rhs;
	return (*this);
}

const char* OfficeBlock::NoSignerException::what() const throw()
{
	return ("No signer in the office");
}

OfficeBlock::NoExecuterException::NoExecuterException(void)
{
	return;
}

OfficeBlock::NoExecuterException::NoExecuterException(NoExecuterException const &eb)
{
	*this = eb;
	return;
}

OfficeBlock::NoExecuterException::~NoExecuterException(void) throw()
{
	return;
}

OfficeBlock::NoExecuterException &OfficeBlock::NoExecuterException::operator=(NoExecuterException const &rhs) 
{
	(void)rhs;
	return (*this);
}

const char* OfficeBlock::NoExecuterException::what() const throw()
{
	return ("No executer in the office");
}