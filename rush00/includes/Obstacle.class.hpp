/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:55:38 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 19:56:11 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_CLASS_HPP
# define OBSTACLE_CLASS_HPP
# include "AEntity.class.hpp"

class Obstacle : public AEntity
{
	public:
		Obstacle(int x, int y, int speed);
		Obstacle(Obstacle const & ref);
		~Obstacle();

		Obstacle&		operator=(Obstacle const & rhs);

		virtual	void	update();

		Obstacle*		clone() const;
	
	private:
		Obstacle();
};

#endif // OBSTACLE_CLASS_HPP
