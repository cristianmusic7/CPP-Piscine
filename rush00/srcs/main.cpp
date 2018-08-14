/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 11:52:52 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 23:10:29 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.class.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	srand(time(NULL));

	GameEngine g;
	int init_status = g.init();

	if (init_status == 0)
       	g.run();
//		g.kill();

   	g.close();

    return 0;
}
