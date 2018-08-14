/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:39:29 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 12:39:30 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP
# include "AEntity.class.hpp"

#include <string>

class Bullet : public AEntity
{
	public:
		Bullet(int);
		Bullet(Bullet const & ref);
		~Bullet();

		Bullet&			operator=(Bullet const & rhs);

		int			getDmg() const;

		/* virtual	void		onCollision(AEntity * other); */
		virtual std::string	print() const;

		virtual	void		update();
	
	private:
		int			_dmg;
};

#endif // BULLET_CLASS_HPP
