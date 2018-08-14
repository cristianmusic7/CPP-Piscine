# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:20:27 by cfranco           #+#    #+#              #
#    Updated: 2018/07/05 13:20:28 by cfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = templates

FLAGS = -Wall -Werror -Wextra

SRC = 	whatever.cpp

OBJS = ft_*.o

ifdef DEBUG
	FLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME):
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME);

re: fclean all

