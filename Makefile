# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sojung <sojung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 13:13:23 by sojung            #+#    #+#              #
#    Updated: 2022/02/04 17:43:30 by sojung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_b

SRC = $(addprefix src/,main.c get_next_line.c get_next_line_utils.c parsing.c \
ft_split.c init.c put_img_env.c put_img_player.c screen.c check_map.c \
update_map.c loops.c set_img.c)

BSRC = $(addprefix bsrc/,main_b.c get_next_line.c get_next_line_utils.c \
parsing_b.c ft_split.c init_b.c put_img_env_b.c put_img_player_b.c screen_b.c \
check_map_b.c update_map_b.c loops_b.c set_img_b.c ft_itoa.c put_img_col.c \
put_img_col_2.c change_enemy_map.c)

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

LIB = ./minilibx-linux/libmlx.a -lXext -lX11 -lm -lz

MLX = ./minilibx-linux/libmlx.a

HEADER = include/

CC = clang

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(MLX) :
	$(MAKE) -C minilibx-linux > /dev/null 2> /dev/null

$(NAME) : $(OBJ) $(MLX)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIB)

bonus : $(BOBJ) $(MLX)
	$(CC) $(FLAGS) $(BOBJ) -o $(BONUS) $(LIB)

%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

clean :
	rm -f $(OBJ) $(BOBJ)
	make clean -C minilibx-linux > /dev/null

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all
