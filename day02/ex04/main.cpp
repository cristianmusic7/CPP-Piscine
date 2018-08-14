/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 01:45:45 by cfranco           #+#    #+#             */
/*   Updated: 2018/06/28 23:28:33 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Fixed.hpp"

int next_op(std::string op_str, char op)
{
	int par = 0;

	for (int i = 0; i < (int)op_str.size(); ++i)
	{
		if (op_str.at(i) == '(')
			par++;
		else if (op_str.at(i) == ')' && par)
			par--;
		else if (!par && op_str.at(i) == op)
			return i;
	}
	return -1;
}

Fixed evaluate(std::string op_str)
{
	int op_size = op_str.size();
	float value;

	while (op_size >= 2 && op_str[0] == '(' && op_str[op_size - 1] == ')')
		op_str = op_str.substr(1, op_size - 2);
	if (op_size == 0)
	{
		std::cout << "Wrong operation format" << std::endl;
		exit(1);
	}

	int op_index = 0;

	if ((op_index = next_op(op_str, '+')) != -1 && op_index != 0 && op_index != op_size)
	{
		if ( op_str.at(op_index - 1) == ')' &&  op_str.at(op_index + 1) == '(')
			return	evaluate(op_str.substr(0, op_index - 1)) +
				evaluate(op_str.substr(op_index + 2, op_size - op_index));
		return	evaluate(op_str.substr(0, op_index)) +
				evaluate(op_str.substr(op_index + 1, op_size - op_index));
	}
	if ((op_index = next_op(op_str, '-')) != -1 && op_index != 0 && op_index != op_size)
	{
		if ( op_str.at(op_index - 1) == ')' &&  op_str.at(op_index + 1) == '(')
			return	evaluate(op_str.substr(0, op_index - 1)) -
				evaluate(op_str.substr(op_index + 2, op_size - op_index));
		return	evaluate(op_str.substr(0, op_index)) -
				evaluate(op_str.substr(op_index + 1, op_size - op_index));
	}
	if ((op_index = next_op(op_str, '*')) != -1 && op_index != 0 && op_index != op_size)
	{
		if ( op_str.at(op_index - 1) == ')' &&  op_str.at(op_index + 1) == '(')
			return	evaluate(op_str.substr(0, op_index - 1)) *
				evaluate(op_str.substr(op_index + 2, op_size - op_index));
		return	evaluate(op_str.substr(0, op_index)) *
				evaluate(op_str.substr(op_index + 1, op_size - op_index));
	}
	if ((op_index = next_op(op_str, '/')) != -1 && op_index != 0 && op_index != op_size)
	{
		if ( op_str.at(op_index - 1) == ')' &&  op_str.at(op_index + 1) == '(')
			return	evaluate(op_str.substr(0, op_index - 1)) /
				evaluate(op_str.substr(op_index + 2, op_size - op_index));
		return	evaluate(op_str.substr(0, op_index)) /
				evaluate(op_str.substr(op_index + 1, op_size - op_index));
	}
	
	try
	{
		value = std::stof(op_str);
	}
	catch (const std::exception&)
	{
		std::cout << "Wrong operation format" << std::endl;
		exit(1);
	}
	return Fixed(value);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string operation;
		std::istringstream ss(argv[1]);
		std::string token;

		while(std::getline(ss, token, ' ')) {
		    operation.append(token);
		}
		std::cout << evaluate(operation) << std::endl;
	}	
	else
		std::cout << "usage ./eval_expr operation" << std::endl;
	return 0;
}
