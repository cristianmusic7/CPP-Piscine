/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleField.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:57:59 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 19:58:33 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLEFIELD_CLASS_HPP
# define OBSTACLEFIELD_CLASS_HPP
# include "Obstacle.class.hpp"
# include "Rect.class.hpp"

class	ObstacleField
{
	public:
		ObstacleField(Rect & rect, int max, int spawn_num);
		ObstacleField(ObstacleField const & ref);
		~ObstacleField();

		ObstacleField& 	operator=(ObstacleField const & rhs);

		void		update();

		int		getSpawnNum() const;
		int		getNumObjects() const;
		void		setNumObjects(int i);
		int		getMaxNumObjects() const;
		Rect&		getBounds() const;

		Obstacle*	getObject(int i) const;
		Obstacle**	getObjects() const;
		void		setObject(int i);

	private:
		ObstacleField();

		int		_max_objects;
		int		_num_objects;

		Obstacle**		_objects;

		int			_spawn_num;

		Rect&			_bounds;
};
#endif // OBSTACLEFIELD_CLASS_HPP
