/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 01:05:42 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 01:05:43 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);		

		Bureaucrat&	operator=(Bureaucrat const & rhs);

		std::string getName(void) const;
		int getGrade(void) const;

		void incrementGrade();
		void decrementGrade();

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
		int 		_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif