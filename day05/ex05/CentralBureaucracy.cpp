/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:30:49 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/03 20:30:51 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	this->_office_blocks = new OfficeBlock[20];
	return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & src)
{
	*this = src;
	return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	delete [] this->_office_blocks;
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy const & rhs) 
{
	(void)rhs;
	return (*this);
}

void	CentralBureaucracy::doBureaucracy(void)
{
	int i = 0;
	int x = 0;

	Intern intern;

	std::string input[] = {"Shrubbery Creation","Presidential Pardon","Robotomy Request"};
	while (i < 20)
	{
		this->_office_blocks[i].setIntern(intern);
		i++;
	}

	i = 0;
	if (this->_targets[0] == "")
	{
		std::cout << "No targets on the queue" << std::endl;
		return;
	}
	while (this->_targets[i] != "")
	{
		x = rand() % 20;
		if (this->_office_blocks[x].getIntern() != NULL && this->_office_blocks[x].getSigner() != NULL
					&& this->_office_blocks[x].getExecutor() != NULL)
		{
			this->_office_blocks[x].doBureaucracy(input[x % 3], this->_targets[i++]);
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << "doBureaucracy completed" << std::endl;
}

void	CentralBureaucracy::feedSigner(Bureaucrat &obj)
{
	int i = 0;

	while (i < 20)
	{
		if (this->_office_blocks[i].getSigner() == NULL)
		{
			this->_office_blocks[i].setSigner(obj);
			return;
		}
		i++;
	}
	std::cout << "queue full, no more signers allowed" << std::endl;
	return;
}

void	CentralBureaucracy::feedExecuter(Bureaucrat &obj)
{
	int i = 0;

	while (i < 20)
	{
		if (this->_office_blocks[i].getExecutor() == NULL)
		{
			this->_office_blocks[i].setExecutor(obj);
			return;
		}
		i++;
	}
	std::cout << "queue full, no more executers allowed" << std::endl;
	return;
}

void	CentralBureaucracy::queueUp(std::string target)
{
	int i = 0;

	while (i < 100)
	{
		if (this->_targets[i] == "")
		{
			this->_targets[i] = target;
			return;
		}
		i++;
	}
	std::cout << "queue full" << std::endl;
	return;
}

int CentralBureaucracy::_srand = std::time(NULL);