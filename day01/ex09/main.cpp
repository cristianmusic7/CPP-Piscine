/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:13:00 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 17:13:04 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(void)
{
	Logger log1("file.txt");

	log1.log("logToConsole", "c++ program working wonderfully");
	log1.log("logToFile", "c++ program working wonderfully");
	return 0;
}
