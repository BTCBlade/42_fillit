# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrady <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 13:48:10 by bbrady            #+#    #+#              #
#    Updated: 2017/03/22 14:06:03 by bbrady           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = gcc -Wall -Wextra -Werror -c

FILE = *.c
SRC = ./src/
SRC_FILES = $(addprefix $(SRC), $(FILE))


OBJ = $(SRC_FILES:c=o)

$(NAME):
		gcc $(SRC_FILES) libft/libft.a -I includes -o fillit

all: $(NAME)

clean:
		rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
