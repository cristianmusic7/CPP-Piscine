/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 01:05:48 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 01:05:49 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main(void)
{
	CentralBureaucracy	cb;
	std::cout << "Central Bureaucracy init" << std::endl;

	try
	{
		cb.doBureaucracy();

		std::cout << std::endl << "creating 10 signers " << std::endl;
		cb.feedSigner(*new Bureaucrat("signer1", 1));
		cb.feedSigner(*new Bureaucrat("signer2", 10));
		cb.feedSigner(*new Bureaucrat("signer3", 25));
		cb.feedSigner(*new Bureaucrat("signer4", 45));
		cb.feedSigner(*new Bureaucrat("signer5", 80));
		cb.feedSigner(*new Bureaucrat("signer6", 120));
		cb.feedSigner(*new Bureaucrat("signer7", 1));
		cb.feedSigner(*new Bureaucrat("signer8", 10));
		cb.feedSigner(*new Bureaucrat("signer9", 25));
		cb.feedSigner(*new Bureaucrat("signer10", 45));
		
		cb.doBureaucracy();

		std::cout << std::endl << "creating 5 executers" << std::endl;
		cb.feedExecuter(*new Bureaucrat("exec1", 1));
		cb.feedExecuter(*new Bureaucrat("exec2", 20));
		cb.feedExecuter(*new Bureaucrat("exec3", 60));
		cb.feedExecuter(*new Bureaucrat("exec4", 110));
		cb.feedExecuter(*new Bureaucrat("exec5", 110));

		cb.doBureaucracy();

		std::cout << std::endl << "creating targets" << std::endl;
		cb.queueUp("Apple");
		cb.queueUp("Banana");
		cb.queueUp("Carrot");
		cb.queueUp("Daikon");
		cb.queueUp("Elephant");
		cb.queueUp("Frost");
		cb.queueUp("Giant");
		cb.queueUp("Hill");
		cb.queueUp("Igloo");
		cb.queueUp("Jack");
		cb.queueUp("Kangaroo");
		cb.queueUp("Lamp");
		cb.queueUp("Michael");
		cb.queueUp("Niagra");
		cb.queueUp("Ostrich");
		cb.queueUp("Platypus");
		cb.queueUp("Quilt");
		cb.queueUp("Razor");
		cb.queueUp("Sand");
		cb.queueUp("Time");
		cb.queueUp("Uvula");
		cb.queueUp("Vuvuzuela");
		cb.queueUp("Walrus");
		cb.queueUp("Xylophone");
		cb.queueUp("Young");
		cb.queueUp("Zebra");

		std::cout << std::endl << "doing Bureaucracy" << std::endl;
		cb.doBureaucracy();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}