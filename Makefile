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

NAME =	fillit
CFLAGS = -Wall -Wextra -Werror -c -Iincludes
CC = 	gcc

FILE = 	back_track_helper.c\
		back_track.c\
		extra_one.c\
		extra_two.c\
		file_io.c\
		fill_matched_pieces_a_e.c\
		fill_matched_pieces_f_j.c\
		fill_matched_pieces_k_o.c\
		fill_matched_pieces_p_s.c\
		grid_file.c\
		grid_struct.c\
		main.c\
		piece_filling.c\
		piece_matching.c\

OBJ = 	$(FILE:.c=.o)
SRC_DIR = 	./src/
SRC_FILES = $(addprefix $(SRC_DIR),$(FILE))

$(NAME): ./includes/header.h $(SRC_FILES)
		@echo "\033[32m["$(NAME)"] compiling "$(NAME)"...\033[0m"
		@$(CC) $(CFLAGS) $(SRC_FILES)
		@$(CC) $(OBJ) -o fillit

all: $(NAME)

clean:
		@echo "\033[31m["$(NAME)"] deleting .o files ...\033[0m"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[31m["$(NAME)"] deleting binary "$(NAME)"...\033[0m"
		@rm -f $(NAME)

re: 	fclean all
