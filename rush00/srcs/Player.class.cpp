/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:03:33 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 23:00:51 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

#include <sstream>
#include <string>

Player::Player(Rect & rect, std::string name) : AEntity(0, 0, 1, '^'), _name(name),
	_bullets(new Bullet*[100]), _num_bullets(0), _hp(100), _bounds(rect)
{
	return ;
}

Player::Player(Player const & ref) : AEntity(0, 0, 1, '^'), _bounds(ref.getBounds())
{
	*this = ref;
	return ;
}

Player::~Player()
{
	return ;
}

Player&			Player::operator=(Player const & rhs)
{
	AEntity::operator=(rhs);
	this->_name = rhs.getName();
	this->_hp = rhs.getHP();
	return (*this);
}

std::string		Player::getName() const
{
	return (this->_name);
}

int			Player::getHP() const
{
	return (this->_hp);
}

void			Player::takeDamage(int dmg)
{
	this->_hp -= dmg;
	return ;
}

void			Player::shoot(int dmg)
{
	this->_bullets[_num_bullets] = new Bullet(100);
	this->_bullets[_num_bullets]->setX(this->_x);
	this->_bullets[_num_bullets]->setY(this->_y - 1);
	this->_num_bullets++;
	dmg = 0;
	return ;
}

std::string		Player::print() const
{
	std::stringstream ss;

	ss << "[Player " << this->getName()
		<< " " << this->getSymbol()
		<< " at (" << this->getX() << ", "
		<< this->getY() << ")]";
	return (ss.str());
}

Rect&			Player::getBounds() const
{
	return (this->_bounds);
}

void			Player::update()
{
	int const bullets = this->_num_bullets;
	for(int i = 0; i < bullets; i++)
	{
		if (!this->_bullets[i])
			continue ;
		this->_bullets[i]->update();
		if (this->_bullets[i]->getY() < this->_bounds.top())
		{
			mvaddch(this->_bullets[i]->getPY(), this->_bullets[i]->getPX(), ' ');
			delete this->_bullets[i];
			this->_bullets[i] = NULL;
			this->_num_bullets--;
		}
	}
	return ;
}

void		Player::setHP(int i){
	this->_hp = i;
}

int			Player::getHP(){
	return (this->_hp);
}

Bullet*		Player::getBullet(int i) const
{
	if (i < 100 && i >= 0)
		return (this->_bullets[i]);
	return (NULL);
}
