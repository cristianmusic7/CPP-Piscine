/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:30:56 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 20:30:58 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Bureaucrat;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		virtual ~Intern(void);		

		Intern&	operator=(Intern const & rhs);

		Form	*makeForm(std::string name, std::string target);
};

#endif
