/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:57:15 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 14:57:17 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);

		std::string identify(void) const;
		const Brain &getBrain(void) const;

	private:
		const Brain _brain;
		std::string _age;
		std::string _name;
};

#endif