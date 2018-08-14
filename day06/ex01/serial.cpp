/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 01:53:35 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/04 01:53:35 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

struct SerialData {
	char s1[8];
	int n;
	char s2[8];
};

void * serialize(void)
{
	SerialData *s = new SerialData;
	std::string alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	s->n = std::rand();	
	for (int i = 0; i < 8; ++i)
	{
		s->s1[i] = alphanum[std::rand() % alphanum.size()];
		s->s2[i] = alphanum[std::rand() % alphanum.size()];
	}
	return reinterpret_cast<void*>(s);
}

Data * deserialize(void * raw)
{
	Data *d = new Data;
	char	*s1 = reinterpret_cast<char*>(raw);
	char	*s2 = s1 + 8 * sizeof(char) + sizeof(int);
	d->n = *reinterpret_cast<int*>(s1 + 8 * sizeof(char));
	d->s1 = std::string(s1);
	d->s1.resize(8);
	d->s2 = std::string(s2);
	d->s2.resize(8);

	SerialData *s = reinterpret_cast<SerialData*>(raw);

	delete s;

	return d;
}

int main(void)
{
	std::srand(rand() % clock());

	Data	*data = deserialize(serialize());

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n:  " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	delete data;
	return(0);
}
