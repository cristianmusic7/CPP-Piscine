# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 01:54:01 by cfranco           #+#    #+#              #
#    Updated: 2018/07/04 03:31:12 by cfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = idrealtype

FLAGS = -Wall -Werror -Wextra

SRC = 	id.cpp

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
