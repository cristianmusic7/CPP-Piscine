/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:30:56 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 20:30:58 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

class Bureaucrat;

class OfficeBlock
{
	public:
		OfficeBlock(void);
		OfficeBlock(Intern &i, Bureaucrat &sb, Bureaucrat &eb);
		virtual ~OfficeBlock(void);

		void	doBureaucracy(std::string name, std::string target);
		void	setIntern(Intern &i);
		void	setSigner(Bureaucrat &sb);
		void	setExecutor(Bureaucrat &eb);

		class NoInternException : public std::exception
		{
			public:
				
				NoInternException(void);
				NoInternException(NoInternException const &obj);
				virtual ~NoInternException(void) throw();
				NoInternException &operator=(NoInternException const &r);
				virtual const char* what() const throw();
		};

		class NoSignerException : public std::exception
		{
			public:
				
				NoSignerException(void);
				NoSignerException(NoSignerException const &obj);
				virtual ~NoSignerException(void) throw();
				NoSignerException &operator=(NoSignerException const &r);
				virtual const char* what() const throw();
		};

		class NoExecuterException : public std::exception
		{
			public:
				
				NoExecuterException(void);
				NoExecuterException(NoExecuterException const &obj);
				virtual ~NoExecuterException(void) throw();
				NoExecuterException &operator=(NoExecuterException const &r);
				virtual const char* what() const throw();
		};

	private:

		OfficeBlock(OfficeBlock &obj);
		OfficeBlock &operator=(OfficeBlock const &r);

		Intern		*_intern;
		Bureaucrat	*_bureau_signer;
		Bureaucrat	*_bureau_executer;
};

#endif
