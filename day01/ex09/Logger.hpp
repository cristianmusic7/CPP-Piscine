/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:12:01 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 17:12:02 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <fstream>
#include <iostream>
#include <string>

class Logger
{
	public:
		Logger(std::string filename);
		~Logger(void);
		void log(std::string const & dest, std::string const & message);

	private:
		void		logToConsole(std::string str);
		void		logToFile(std::string str);
		std::string	makeLogEntry(std::string message);
		std::string	_filename;
};

#endif
