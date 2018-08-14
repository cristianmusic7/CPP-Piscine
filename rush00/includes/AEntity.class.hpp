/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 11:36:36 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 11:52:44 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_CLASS_HPP
# define AENTITY_CLASS_HPP

#include <ncurses.h>
# include <iostream>

class	AEntity
{
	public:
		AEntity(int x, int y, int speed, char symbol);
		AEntity(AEntity const & ref);
		virtual ~AEntity();

		AEntity&		operator=(AEntity const & rhs);

		int			getX() const;
		int			getY() const;
		int			getPX() const;
		int			getPY() const;
		int			getSpeed() const;
		char			getSymbol() const;

		void			setX(int);
		void			setY(int);
		void			setPX(int);
		void			setPY(int);
		void			setSpeed(int);
		void			setSymbol(char symbol);


		void			draw() const;
		void			draw(int x, int y);
		void			clear() const;

		virtual	void		update() = 0;
		virtual	void		onCollision(AEntity * other);
		virtual	std::string	print() const;

	private:
		AEntity(void);

	protected:
		int			_x;
		int			_y;
		int			_px;
		int			_py;

		int			_speed;

		char			_symbol;
};

std::ostream	&	operator<<(std::ostream	& o, AEntity const & rhs);
#endif // AENTITY_CLASS_HPP
