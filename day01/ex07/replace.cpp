/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:07:29 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/27 16:07:30 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int validateInput(std::string filename, std::string s1, std::string s2, std::ifstream& ifs)
{
	if (!s1.compare(s2))
	{
		std::cout << "strings need to be different" << std::endl;
		return (0);
	}
	if (!filename.size() || !s1.size() || !s2.size())
	{
		std::cout << "one or more arguments are empty" << std::endl;
		return (0);
	}
	else if ( ifs.peek() == std::ifstream::traits_type::eof() )
	{
		std::cout << "file doesn't exists or is empty" << std::endl;
		return (0);  
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string filename(argv[1]);
		std::string s1(argv[2]);
		std::string s2(argv[3]);
		std::ifstream ifs(argv[1]);

		if (validateInput(filename, s1, s2, ifs))
	  	{
	  		std::string content( (std::istreambuf_iterator<char>(ifs) ),
	                       (std::istreambuf_iterator<char>()));

	  		if (!(content.find(s1) != std::string::npos))
	  		{
	  			std::cout << "word not found in file" << std::endl;
	  			return (0);
	  		}
	  		content.replace(content.find(s1),s1.size(),s2);
	  		while (content.find(s1)!=std::string::npos)
		    	content.replace(content.find(s1),s1.size(),s2);
		    std::ofstream ofs(filename + ".replace");
		    ofs << content;
		    ofs.close();
		    std::cout << filename + ".replace created" << std::endl;
	  	}	  	
	}
	else
		std::cout << "usage: filename s1 s2" << std::endl;	
	return 0;
}
