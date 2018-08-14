# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpollore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 15:14:08 by jpollore          #+#    #+#              #
#    Updated: 2018/07/01 22:54:33 by jpollore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
HEADER = includes/
SRC = srcs/
LIB = ncurses
NAME = ft_retro 
CS = AEntity.class Player.class Bullet.class Obstacle.class GameEngine.class
CS += ObstacleField.class Rect.class main
SRCS = $(addprefix $(SRC), $(addsuffix .cpp, $(CS)))
OBJS = $(addsuffix .o, $(CS))
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I$(HEADER)

ifeq ($(CDEBUG), 1)
	CFLAGS += -g
endif

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -l$(LIB)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
