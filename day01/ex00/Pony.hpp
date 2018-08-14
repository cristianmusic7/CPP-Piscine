/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 03:23:25 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 03:23:27 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
	public:

		Pony(std::string name, std::string color, std::string mood);
		~Pony(void);
		void greet(void) const;

	private:
		std::string _name;
		std::string _color;
		std::string _mood;
};

#endif
