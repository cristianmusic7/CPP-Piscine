/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 22:54:17 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 23:08:37 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.class.hpp"
#include "Player.class.hpp"
#include "ObstacleField.class.hpp"
#include "Rect.class.hpp"

GameEngine::GameEngine(void)
{
	std::cout << "GameEngine created!" << std::endl;
}

GameEngine::GameEngine(GameEngine const & src)
{
	std::cout << "Copy GameEngine created!" << std::endl;
	*this = src;
	return;
}

GameEngine::~GameEngine(void)
{
	std::cout << "GameEngine died!" << std::endl;
}


GameEngine&	GameEngine::operator=(GameEngine const & rhs)
{
	this->_window = rhs._window;
	return *this;
}


void	GameEngine::draw() const
{
	std::cout << "Drawing " << std::endl;
}


void	GameEngine::draw(Player & entity, int x, int y)
{
	Rect&	bounds = entity.getBounds();

	if (x >= bounds.right())
		x = bounds.right();
	if (y >= bounds.bot())
		y = bounds.bot();

	if (x <= bounds.left())
		x = bounds.left();
	if (y <= bounds.top())
		y = bounds.top();

	entity.setPX(entity.getX());
	entity.setPY(entity.getY());
	entity.setX(x);
	entity.setY(y);

	mvaddch(entity.getPY(), entity.getPX(), ' ');
	mvaddch(entity.getY(), entity.getX(), entity.getSymbol());
}

void	GameEngine::draw(Obstacle & entity, unsigned int x, unsigned int y)
{
	entity.setPX(entity.getX());
	entity.setPY(entity.getY());
	entity.setX(x);
	entity.setY(y);
	mvaddch(entity.getPY(), entity.getPX(), ' ');
	mvaddch(entity.getY(), entity.getX(), entity.getSymbol());
}

void	GameEngine::draw(Bullet & entity, unsigned int x, unsigned int y)
{
	entity.setPX(entity.getX());
	entity.setPY(entity.getY());
	entity.setX(x);
	entity.setY(y);
	mvaddch(entity.getPY(), entity.getPX(), ' ');
	mvaddch(entity.getY(), entity.getX(), entity.getSymbol());
}


int	GameEngine::init(void)
{
	this->_window = initscr();
	cbreak();
	noecho();
	clear();
	refresh();

	keypad(this->_window, true);
	nodelay(this->_window, true);
	curs_set(0);

	if(!has_colors())
	{
		endwin();
		printf("ERROR: Terminal does not support color.\n");
		exit(1);
	}

	start_color();

	attron(A_BOLD);
	box(this->_window, 0, 0);
	attroff(A_BOLD);

	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	wbkgd(this->_window, COLOR_PAIR(1));

	return 0;
}

void	GameEngine::run(void)
{
	int cycles = 0;
	int maxy = 0;
	int maxx = 0;

	getmaxyx(this->_window, maxy, maxx);
	Rect		rect(2, 2, maxx, maxy);
	ObstacleField	objects(rect, 2000, 5);

	Player player(rect, "new");
	player.setX(rect.width() / 2);
	player.setY(rect.bot());
	player.setSpeed(1);
	player.setHP(5);

	int in_char;

	while(1)
	{
		in_char = wgetch(this->_window);
		this->draw(player,
				player.getX() + (in_char == KEY_RIGHT) - (in_char == KEY_LEFT),
				player.getY() + (in_char == KEY_DOWN) - (in_char == KEY_UP));

		if (in_char == ' ')
			player.shoot(100);

		if (!(cycles % 5))
		{
			player.update();
				for (int i = 0; i < 100; i++)
				{
					if (player.getBullet(i) == NULL)
						continue ;
					mvaddch(player.getBullet(i)->getPY(),
							player.getBullet(i)->getPX(), ' ');
					mvaddch(player.getBullet(i)->getY(),
							player.getBullet(i)->getX(),
							player.getBullet(i)->getSymbol());

					for (int j = 0; j < objects.getMaxNumObjects(); j++)
					{
						if (objects.getObject(j) == NULL)
							continue ;
						if (objects.getObject(j)->getY() == player.getBullet(i)->getY() &&
								objects.getObject(j)->getX() == player.getBullet(i)->getX())
						{
							objects.getObject(j)->setSymbol(' ');
							delete objects.getObject(j);
							objects.setObject(j);
							objects.setNumObjects(objects.getNumObjects() - 1);
						}
					}
				}
		}

		if (cycles == 10)
		{
			objects.update();
			for (int i = 0; i < objects.getMaxNumObjects(); i++)
			{
				if (objects.getObject(i) == NULL)
					continue ;
				mvaddch(objects.getObject(i)->getPY(), objects.getObject(i)->getPX(), ' ');

				if (objects.getObject(i)->getY() == player.getY() &&
							objects.getObject(i)->getX() == player.getX()){
					player.setHP(player.getHP() - 1);
					if (player.getHP() == 0)
						break ;
				}
				mvaddch(objects.getObject(i)->getY(),
						objects.getObject(i)->getX(),
						objects.getObject(i)->getSymbol());
			}
			cycles = 0;
			if (player.getHP() == 0)
				break;
		}
		cycles++;
		usleep(10000); // 10 ms
		refresh();
	}
}

void	GameEngine::kill(){
	this->_window = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
}

void	GameEngine::close(void)
{
	endwin();
}
