/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:15:32 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 18:15:33 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int validateInput(std::string filename, std::ifstream& ifs)
{
	if ( ifs.fail() )
	{
	    std::cerr << filename << ": " << strerror(errno) << std::endl;
	    return(1);
	}
	return (1);
}

void handle_stdin(void)
{
	std::string content;
	while (getline(std::cin,content))
	{
		std::cout << content << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string filename(argv[i]);

			if (!filename.compare("-"))
				handle_stdin();
			else
			{
				std::ifstream ifs(argv[i]);
				if (validateInput(filename, ifs))
			  	{
			  		std::string content( (std::istreambuf_iterator<char>(ifs) ),
			                       (std::istreambuf_iterator<char>()));
				    std::cout << content;
			  	}	
			}			  	
		}		
	}
	else
		handle_stdin();
	return 0;
}
