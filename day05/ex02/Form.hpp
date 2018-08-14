/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 01:05:42 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 01:05:43 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const & src);
		virtual ~Form(void);		

		Form&	operator=(Form const & rhs);

		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;

		void beSigned(Bureaucrat & b);

		virtual void execute(Bureaucrat const & executor) const;

		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & rhs);
				virtual ~GradeTooHighException(void) throw();

				GradeTooHighException&	operator=(GradeTooHighException const &);

				virtual const char* what() const throw();	
		};

		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & rhs);
				virtual ~GradeTooLowException(void) throw();

				GradeTooLowException&	operator=(GradeTooLowException const &);

				virtual const char* what() const throw();	
		};

	private:
		std::string _name;
		int 		_sign_grade;
		int 		_exec_grade;
		bool 		_signed;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);

#endif