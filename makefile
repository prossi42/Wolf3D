# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 12:07:08 by prossi            #+#    #+#              #
#    Updated: 2017/09/07 13:56:44 by prossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, opti, clean, fclean, re

NAME = wolf3d

SRC_PATH = src

SRC_NAME = main.c ft_affich.c ft_parsing.c ft_init_struct.c ft_get_number.c \
ft_mlx.c key_hook.c free_all.c cross_exit.c find_a_place.c raycaster.c \
fps_counter.c

# OBJ_PATH = $(SRC_PATH)

LDFLAGS = -Llibft
LDLIBS = libft/my_libft.a mlx/libmlx.a

CC = gcc -Wall -Wextra -Werror
CFLAGS = -framework OpenGL -framework Appkit
CFLAGSOPTI = -framework OpenGL -framework Appkit -O3 -march=native

# OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
# OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

opti: $(SRC)
		cd libft/ ; make re ; make clean ; cd ..
		cd mlx/ ; make re ; cd ..
		$(CC) $(LDFLAGS) $(LDLIBS) -o wolf3d $^ $(CFLAGSOPTI)

$(NAME): $(SRC)
	cd libft/ ; make re; make clean ; cd ..
	cd mlx/ ; make re ; cd ..
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^ $(CFLAGS)

clean:
	cd mlx/ ; make clean ; cd ..
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	cd libft/ ; make fclean ; cd .. ; rm -fv $(NAME)

re: fclean all

reopti: fclean opti
