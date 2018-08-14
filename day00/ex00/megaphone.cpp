/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 02:30:16 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/26 02:30:18 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

int		main(int argc, char **argv)
{
	int length;
	int c;
	int i;

	i = 1;
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			c = 0;
			length = ft_strlen(argv[i]);
			while (c < length)
			{
				if (argv[i][c] >= 'a' && argv[1][c] <= 'z')
					argv[i][c] -= 32;
				c++;
			}
			std::cout << argv[i++];
		}
		std::cout << std::endl;
	}
	return (0);
}
