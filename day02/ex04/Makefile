# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 23:26:58 by cfranco           #+#    #+#              #
#    Updated: 2018/06/28 23:27:26 by cfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

FLAGS = -Wall -Werror -Wextra

SRC = 	Fixed.cpp \
		main.cpp

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

