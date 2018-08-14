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

class Base
{
	public:
		virtual ~Base()
		{};	
};

class A : public Base
{ };

class B : public Base
{ };

class C : public Base
{ };

Base * generate(void)
{
	int inst = std::rand() % 3;
	if (inst == 0)
	{
		std::cout << "instace A created" << std::endl;
		return reinterpret_cast<Base*>(new A);
	}
	else if (inst == 1)
	{
		std::cout << "instace B created" << std::endl;
		return reinterpret_cast<Base*>(new B);
	}
	else
	{
		std::cout << "instace C created" << std::endl;
		return reinterpret_cast<Base*>(new C);
	}
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C pointer" << std::endl;
}

void identify_from_reference(Base & p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A reference" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B reference" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C reference" << std::endl;
}

int main(void)
{
	std::srand(rand() % clock());

	Base	*b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);

	Base	*b2 = generate();
	identify_from_pointer(b2);
	identify_from_reference(*b2);

	delete b;
	delete b2;

	return(0);
}
