/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:25:51 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/06 14:26:06 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>

template <typename T>
int easyfind(T & container, int n)
{
	typename T::const_iterator iter;	

	int i = 0;

	for (iter = std::begin(container); iter != std::end(container); iter++)
	{
   		if (*iter == n)
   			return (i);
   		i++;
	}
	throw std::exception();
}

#endif

