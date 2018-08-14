/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleField.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:57:20 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 19:57:30 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObstacleField.class.hpp"

#include <ncurses.h>

ObstacleField::ObstacleField(Rect & rect, int max, int spawn_num)
	: _max_objects(max),
	_num_objects(0),
	_objects(new Obstacle*[max]),
	_spawn_num(spawn_num),
	_bounds(rect)
{
	return ;
}

ObstacleField::~ObstacleField()
{
	for(int i = 0; i < this->_max_objects; i++)
	{
		if (this->_objects[i])
			delete this->_objects[i];
	}
	delete	[] this->_objects;
}

ObstacleField::ObstacleField(ObstacleField const & ref) : _bounds(ref.getBounds()) 
{
	this->_num_objects = ref.getNumObjects();
	for (int i = 0; i < this->_num_objects; i++)
		this->_objects[i] = ref.getObject(i)->clone();
	return ;
}

ObstacleField& 	ObstacleField::operator=(ObstacleField const & rhs)
{
	for (int i = 0; i < this->_num_objects; i++)
		delete this->_objects[i];
	delete	[] this->_objects;

	this->_objects = new Obstacle*[rhs.getMaxNumObjects()];

	this->_num_objects = rhs.getNumObjects();
	for (int i = 0; i < this->_num_objects; i++)
		this->_objects[i] = rhs.getObject(i)->clone();
	return (*this);
}

int		ObstacleField::getNumObjects() const
{
	return (this->_num_objects);
}

void		ObstacleField::setNumObjects(int n)
{
		this->_num_objects = n;
}

int		ObstacleField::getMaxNumObjects() const
{
	return (this->_max_objects);
}

int		ObstacleField::getSpawnNum() const
{
	return (this->_spawn_num);
}

Rect&		ObstacleField::getBounds() const
{
	return (this->_bounds);
}

Obstacle*	ObstacleField::getObject(int i) const
{
	if (i < this->_max_objects && i >= 0)
		return (this->_objects[i]);
	return (NULL);
}

void	ObstacleField::setObject(int i)
{
	this->_objects[i] = NULL;
}

Obstacle**	ObstacleField::getObjects() const
{
	return (this->_objects);
}

void		ObstacleField::update()
{
	int const objects = this->_num_objects;
	for(int i = 0; i < objects; i++)
	{
		if (!this->_objects[i])
			continue ;
		this->_objects[i]->update();
		if (this->_objects[i]->getY() > this->_bounds.bot())
		{
			mvaddch(this->_objects[i]->getPY(), this->_objects[i]->getPX(), ' ');
			delete this->_objects[i];
			this->_objects[i] = NULL;
			this->_num_objects--;
		}
	}

	int spawn_num = 0;
	if (this->_num_objects + this->_spawn_num > this->_max_objects)
		spawn_num = this->_max_objects - (this->_num_objects + this->_spawn_num);
	else
		spawn_num = this->_spawn_num;
	
	for (int j = 0; j < this->_max_objects; j++)
	{
		if (spawn_num == 0)
			break ;
		if (this->_objects[j] == NULL)
		{
			this->_objects[j] = new Obstacle(rand() % this->_bounds.width() + this->_bounds.getOffsetX(), 2, 1);
			this->_num_objects++;
			spawn_num--;
		}
	}
}
