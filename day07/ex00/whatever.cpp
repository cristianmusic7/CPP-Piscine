/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:20:13 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/05 13:20:14 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


template <typename T>
void swap(T & x, T & y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
	return;
}

template <typename T>
T const & max(T const & x, T const & y)
{
	return (x>y ? x : y);
}

template <typename T>
T const & min(T const & x, T const & y)
{
	return (x<y ? x : y);
}

int main(void)
{
	int a = 21;
	int b = 47;

	std::cout << "values par1: " << a  << " par2: " << b << std::endl; 

	std::cout << "max: " << std::endl; 
	std::cout << max<int>(a,b) << std::endl;


	std::cout << "min: " << std::endl; 
	std::cout << min<int>(a,b) << std::endl;

	swap<int>(a,b);
	std::cout << "swapped values par1: " << a  << " par2: " << b << std::endl; 

	float c = 2.4f;
	float d = -7.2f;

	std::cout << "values par1: " << c  << " par2: " << d << std::endl; 

	std::cout << "max: " << std::endl; 
	std::cout << max<float>(c,d) << std::endl;


	std::cout << "min: " << std::endl; 
	std::cout << min<float>(c,d) << std::endl;

	swap<float>(c,d);
	std::cout << "swapped values par1: " << c  << " par2: " << d << std::endl; 	

	char r = 'r';
	char t = 't';

	std::cout << "values par1: " << r  << " par2: " << t << std::endl; 

	std::cout << "max: " << std::endl; 
	std::cout << max<char>(r,t) << std::endl;


	std::cout << "min: " << std::endl; 
	std::cout << min<char>(r,t) << std::endl;

	swap<char>(r,t);
	std::cout << "swapped values par1: " << r  << " par2: " << t << std::endl;

	return 0;
}