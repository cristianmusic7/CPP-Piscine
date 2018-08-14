# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 02:30:39 by cfranco           #+#    #+#              #
#    Updated: 2018/06/26 02:30:42 by cfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

#INC = 

#LIBS = -L libft -lft -lmlx

FLAGS = -Wall -Werror -Wextra

SRC = 	Contact.class.cpp \
		phonebook.cpp

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

