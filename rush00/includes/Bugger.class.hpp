/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bugger.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:43:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/07/01 22:07:12 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUGGER_CLASS_HPP
# define BUGGER_CLASS_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Enemy.class.hpp"

class Bugger : public Enemy {
	public:
		Bugger();
		virtual ~Bugger();
		Bugger(int x, int y);
		Bugger(Bugger &);
		Bugger	&operator=(Bugger const &);
		int		movement(int r, int b);
		int		getLife();
};

#endif
