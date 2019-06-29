# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 19:01:08 by rrhaenys          #+#    #+#              #
#    Updated: 2019/02/20 17:23:15 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rrhaenys.filler
NAME_VIS = filler_vis
COMMAND = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
SRC_FIL = $(shell ls src | grep -E ".+\.c")
SRCS = $(addprefix  $(SRC_DIR), $(SRC_FIL))
OBJ	= $(SRCS:.c=.o)
SRC_DIR_VIS = visual/
SRC_FIL_VIS = $(shell ls visual | grep -E ".+\.c")
SRCS_VIS = $(addprefix  $(SRC_DIR_VIS), $(SRC_FIL_VIS))
OBJ_VIS	= $(SRCS_VIS:.c=.o)
INCLUDE = -I libft/src -I includes
LIB = ./libft/libft.a
MLX = -framework OpenCL -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(NAME_VIS)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	$(COMMAND) $(FLAGS) -g -o $(NAME) $(INCLUDE) $(OBJ) $(LIB)

$(NAME_VIS): $(LIB) $(OBJ_VIS)
	$(COMMAND) $(FLAGS) -g -o $(NAME_VIS) $(INCLUDE) $(OBJ_VIS) $(LIB) $(MLX)

.c.o:
	$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_VIS)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME_VIS)

re: fclean all

.PHONY: clean fclean all re