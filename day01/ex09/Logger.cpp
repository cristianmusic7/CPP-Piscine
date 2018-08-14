/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:11:56 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 17:11:57 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string filename)
:_filename(filename){ }

Logger::~Logger(void){ }

void Logger::log(std::string const & dest, std::string const & message)
{
	void	(Logger::*f[2])(std::string message);

	f[0] = &Logger::logToConsole;
	f[1] = &Logger::logToFile;

	std::string names[2] = {"logToConsole","logToFile"};

	for (int i = 0; i < 2; ++i)
	{
		if(!names[i].compare(dest))
			(this->*f[i])(message);
	}
}

void Logger::	logToConsole(std::string message)
{
	std::cout << this->makeLogEntry(message) << std::endl;
}

void Logger::	logToFile(std::string message)
{
	std::ofstream outfile;
	outfile.open(this->_filename, std::ios_base::app);
	outfile << this->makeLogEntry(message) << std::endl;
}


std::string	Logger::	makeLogEntry(std::string message)
{
	std::string formatted;

	time_t		cur = time(NULL);
	struct tm	*local_t = localtime(&cur);
	char		time_str[64];

	strftime(time_str, sizeof(time_str), "%Y/%m/%d %H:%M:%S --> ", local_t);

	formatted = std::string (time_str) + "log: " + message;
	return(formatted);
}
