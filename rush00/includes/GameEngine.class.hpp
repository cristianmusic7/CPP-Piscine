/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 14:36:42 by cfranco           #+#    #+#             */
/*   Updated: 2018/07/01 23:09:01 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_CLASS_HPP
# define GAMEENGINE_CLASS_HPP

#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "Player.class.hpp"
#include "Obstacle.class.hpp"
#include "Bullet.class.hpp"

class GameEngine
{
	public:
		GameEngine(void);
		GameEngine(GameEngine const & src);
		~GameEngine(void);		

		GameEngine&	operator=(GameEngine const & rhs);

		void			draw() const;
		void			draw(Player & entity, int x, int y);
		void			draw(Obstacle & entity, unsigned int x, unsigned int y);
		void			draw(Bullet & entity, unsigned int x, unsigned int y);
		//void			clear() const;

		int		init(void);
		void	run(void);
		void	kill();
		void	close(void);

	private:
		
		WINDOW*			_window;
};

#endif // GAMEENGINE_CLASS_HPP
