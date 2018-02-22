# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 09:52:46 by agalavan          #+#    #+#              #
#    Updated: 2018/02/20 09:52:49 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = agalavan.filler

# project directories

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./libftprintf/

# project source files

SRC =	main.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT = $(LIB_DIR)libftprintf.a
LIBFT_INC := $(LIB_DIR)inc/

# compilation flags

FLAGS := -Wall -Wextra -Werror -O3

# header flags

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		@ gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		@ make -C $(LIB_DIR)

clean:
		@ rm -f $(OBJ)
		@ make clean -C $(LIB_DIR)

fclean: clean
		@ rm -f $(NAME)
		@ make fclean -C $(LIB_DIR)
		@ rm -rf $(OBJ_DIR)

re: fclean all

# special stuff

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
