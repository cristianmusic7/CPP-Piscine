/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:30:56 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 20:30:58 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CentralBureaucracy_HPP
# define CentralBureaucracy_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

class Bureaucrat;

class CentralBureaucracy
{
	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy const & src);
		virtual ~CentralBureaucracy(void);		

		CentralBureaucracy&	operator=(CentralBureaucracy const & rhs);

		void	feedSigner(Bureaucrat &s);
		void	feedExecuter(Bureaucrat &e);

		void	queueUp(std::string queue);

		void	doBureaucracy(void);

	private:
		OfficeBlock		*_office_blocks;
		std::string		_targets[100];

		static int _srand;
};

#endif
