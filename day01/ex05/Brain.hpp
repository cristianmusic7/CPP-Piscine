/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:56:56 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 14:56:57 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <sstream>
#include <iostream>
#include <string>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		std::string identify(void) const;

	private:
		std::string _cleverness;
};

#endif