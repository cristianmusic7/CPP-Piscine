/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bugger.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:43:45 by jmeier            #+#    #+#             */
/*   Updated: 2018/07/01 22:07:52 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Bugger.class.hpp"
#include "Enemy.class.hpp"

Bugger::Bugger() : Enemy () {
	return ;
}

Bugger::Bugger(int x, int y, int life) : Enemy(x, y, 1){
	return ;
}

Bugger::~Bugger(int i) : ~Enemy(i){
	return;
}

Bugger::Bugger(Bugger &that){
	*this = that;
}

Bugger	&Bugger::operator=(Bugger const &ref){
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

//need to figure out exactly what I'm going to pass here
//Map dimensions so that if they cross borders, life goes to zero
//A loop should in such a way that something along the lines of
//while (movement()){
//	Bugger.collision();
// 	refresh();
//	usleep(100) or whatever some spane of time
// }
//r is the right boundary of the map. b is the bottom bound
int		movement(int r, int b){
	float prob = 1.0 * rand() / RAND_MAX;

	if (prob < 0.47) {
		if (this->_x > 2)
			moveLeft();
		else
			moveRight();
	}
	else if (prob < 0.95) {
		if (this->_x < r)
			moveRight();
		else
			moveLeft();
	}
	else {
		if (this->_y < (b - 2))
			moveDown();
		else { 
			this->_life = 0;
			// erases the enemy
			mvprintw(this->_y, this->_x, " ");
			return (1);
		}
	}
	return (0);
}

int		Bugger::getLife(){
	return (this->_life);
}