# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 17:06:54 by apluzhni          #+#    #+#              #
#    Updated: 2019/04/04 14:44:48 by apluzhni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAG = -Wall -Wextra -Werror

MLX_LNK = -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB_LNK = -L ./libft/ -lft
MAT_LNK = -lm

SRC_DIR = ./source/
OBJ_DIR = ./object/
INC_DIR = ./include/
LIB_DIR = ./libft/

SRC = main.c fdf_read.c fdf_draw.c fdf_events_key.c fdf_events_mouse.c
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC = $(addprefix $(INC_DIR),fdf.h)
LIB = libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@gcc -g $(FLAG) $(LIB_LNK) $(MLX_LNK) $(MAT_LNK) $(addprefix $(SRC_DIR),$(SRC)) -o $(NAME)

$(LIB):
	@make -C ./libft/

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAG) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./libft/ fclean
	@rm -f $(NAME)
	@rm -rf fdf.dSYM

re: fclean all

kill:
	@pkill fdf

.PHONY: clean fclean re kill
