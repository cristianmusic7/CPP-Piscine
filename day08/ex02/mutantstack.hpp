/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:05:50 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/06 21:05:52 by cfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:

	MutantStack(void)
	{ }

	MutantStack(MutantStack const & src)
	{
		*this = src;
	}

	~MutantStack(void)
	{ }

	MutantStack&	operator=(MutantStack const & rhs)
	{
		*this = rhs;
	}

	class iterator {		
		public:
			iterator(iterator const &_stack)
			:_stack(_stack._stack), i(_stack.i)
			{}

			iterator(MutantStack &st, unsigned int i)
			:_stack(st), i(i)
			{}

			~iterator()
			{}

			iterator	&operator++()
			{
				if (i < _stack.size())
					i++;
				return (*this);
			}

			iterator	&operator--() {
				if (i > 0)
					i--;
				return (*this);
			}

			bool	operator==(iterator const &_stack){
				return (i == _stack.i);
			}

			bool	operator!=(iterator const &_stack) {
				return (i != _stack.i);
			}

			T		&operator*() {
				return _stack.c[i];
			}

		private:
			MutantStack& 	_stack;
			unsigned int	i;

			iterator	&operator=(iterator const &_stack);
			iterator();
	};

	iterator	begin()
	{
		return (iterator(*this, 0));
	}

	iterator	end()
	{
		return (iterator(*this, this->size()));
	}
};


#endif
