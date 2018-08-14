/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:03:41 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 22:59:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "AEntity.class.hpp"
# include "Bullet.class.hpp"
# include "Rect.class.hpp"

#include <string>

class Player : public AEntity
{
	public:
		Player(Rect & rect, std::string name);
		Player(Player const & ref);
		~Player();

		Player&			operator=(Player const & rhs);

		std::string		getName() const;
		int			getHP()	const;
		Rect&		getBounds() const;

		void			takeDamage(int);
		void 			shoot(int dmg);
		void			bullet_update();
		Bullet*			getBullet(int i) const;
		void			setHP(int i);
		int				getHP();
		
		/* virtual	void		onCollision(AEntity * other); */
		virtual std::string	print() const;
		virtual	void		update();
	
	private:
		Player();

		std::string		_name;

		Bullet**		_bullets;
		int			_num_bullets;

		int			_hp;

		Rect&			_bounds;
};

#endif // PLAYER_CLASS_HPP
