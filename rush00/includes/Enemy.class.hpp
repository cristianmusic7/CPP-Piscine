/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:05:06 by jmeier            #+#    #+#             */
/*   Updated: 2018/07/01 22:06:47 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class Enemy {
	public:
		Enemy();
		Enemy(int x, int y, int life);
		virtual ~Enemy(int i);
		Enemy(Enemy const &);
		Enemy	&operator=(Enemy const &);

		int		moveRight();
		int		moveLeft();
		int		moveDown();
		int		collision(int x, int y);
	protected:
		int		_x;
		int		_y;
		int		_life;
};

#endif
