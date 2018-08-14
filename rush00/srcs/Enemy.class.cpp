/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:05:04 by jmeier            #+#    #+#             */
/*   Updated: 2018/07/01 22:07:46 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Enemy.class.hpp"

Enemy::Enemy(){
	return ;
}

Enemy::Enemy(int x, int y, int l): _x(x), _y(y), _life(l){
	return
}

Enemy::~Enemy(int i){
	if (i == 1){
		//stop the game here.  You've collided with a player
		//There's probably an ncurses thing to clear the screen
	}
	(void)i
	return;
}

Enemy::Enemy(Enemy const &that){
	*this = that;
}

Enemy	&Enemy::operator=(Enemy const &ref){
	this->_x = ref._x;
	this->_y = ref._y;
	this->_life = ref._life;
	return (*this);
}

int		Enemy::moveRight(){
	this->_y++;
}

int		Enemy::moveLeft(){
	this->x--;
}

int		Enemy::moveDown(){
	this->x++;
}

//pass in the coordinates of whatever is being checked.  Bullet x&y or playerx&y
int		collision(int x, int y){
	if (this->_x == x && this->_y == y){
		this->life = 0;
		return (1);
	}
	return (0);
}