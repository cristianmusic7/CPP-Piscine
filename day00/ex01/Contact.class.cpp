/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:31:01 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/26 17:31:03 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact(void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_login = "";
	this->_postal_address = "";
	this->_email = "";
	this->_phone_number = "";
	this->_birthday_date = "";
	this->_favorite_meal = "";
	this->_underwear_color = "";
	this->_darkest_secret = "";
	return;
}

Contact::~Contact(void)
{
	std::cout << "contact deleted." << std::endl;
	return;
}

void Contact::AddData(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::cout << "Enter contact's first name:";
	std::getline(std::cin, this->_first_name);
	std::cout << "Enter contact's last name: ";
	std::getline(std::cin, this->_last_name);
	std::cout << "Enter contact's nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Enter contact's login: ";
	std::getline(std::cin, this->_login);
	std::cout << "Enter contact's postal address: ";
	std::getline(std::cin, this->_postal_address);
	std::cout << "Enter contact's email: ";
	std::getline(std::cin, this->_email);
	std::cout << "Enter contact's phone number: ";
	std::getline(std::cin, this->_phone_number);
	std::cout << "Enter contact's birthday: ";
	std::getline(std::cin, this->_birthday_date);
	std::cout << "Enter contact's favorite meal: ";
	std::getline(std::cin, this->_favorite_meal);
	std::cout << "Enter contact's underwear color: ";
	std::getline(std::cin, this->_underwear_color);
	std::cout << "Enter contact's darkest secret: ";
	std::getline(std::cin, this->_darkest_secret);
	std::cout << "New contact info updated" << std::endl;
	return;
}

void Contact::PrintData(void) const
{	
	std::cout << "First Name: ";
	std::cout << this->_first_name << std::endl;
	std::cout << "Last Name: ";
	std::cout << this->_last_name << std::endl;
	std::cout << "Nickname: ";
	std::cout << this->_nickname << std::endl;
	std::cout << "Login: ";
	std::cout << this->_login << std::endl;
	std::cout << "Postal address: ";
	std::cout << this->_postal_address << std::endl;
	std::cout << "Email Address: ";
	std::cout << this->_email << std::endl;
	std::cout << "Phone Number: ";
	std::cout << this->_phone_number << std::endl;
	std::cout << "Birthday: ";
	std::cout << this->_birthday_date << std::endl;
	std::cout << "Favorite Meal: ";
	std::cout << this->_favorite_meal << std::endl;
	std::cout << "Underwear Color: ";
	std::cout << this->_underwear_color << std::endl;
	std::cout << "Darkest Secret: ";
	std::cout << this->_darkest_secret << std::endl;
	return;
}

std::string Contact::getFirstname(void) const
{
	return (this->_first_name);
}

std::string Contact::getLastname(void) const
{
	return (this->_last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}
