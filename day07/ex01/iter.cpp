/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:20:21 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/05 16:20:22 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <string>

template <typename T>
void iter(T * addr, size_t arr_len, void (*func)(T &))
{
	for (size_t i = 0; i < arr_len; ++i)
	{
		func(addr[i]);
	}
	return;
}

template <typename T>
void square(T & num)
{
	num *= num;
}

template <typename T>
void print(T & item)
{
	std::cout << item << std::endl;
}

void upper(char & c)
{
	c = toupper(c);
}

void lower(char & c)
{
	c = tolower(c);
}

int main(void)
{
	int	nums[5] = {4,7,1,2,4};
	
	iter(nums, 5, square);
	iter(nums, 5, print);

	float	fnums[9] = {4.2f,0.7f,1.6f,2.1f,-4.0f,-5.0f,6.6f,2.9f,-100.6f};
	iter(fnums, 9, square);
	iter(fnums, 9, print);

	char str[] = "print chars!";
	iter(str, std::strlen(str), upper);
	iter(str, std::strlen(str), print);

	std::string strs[] = {"asdsad","asdasd","2234234234"};
	iter(strs, 3, print);

	char str2[] = "SOME WORDs IN UPPERCASE!";
	iter(str2, std::strlen(str2), lower);
	return 0;
}


