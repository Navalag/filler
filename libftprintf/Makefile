# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 13:16:08 by agalavan          #+#    #+#              #
#    Updated: 2018/02/07 13:16:10 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# project directories

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./libft/

# project source files

SRC =	ft_printf.c \
		read_flags.c \
		generate_res_func.c \
		print_res_func_1.c \
		print_res_func_2.c \
		set_flag_func_1.c \
		set_flag_func_2.c \
		set_flag_func_3.c \
		read_n_cast_1.c \
		read_n_cast_2.c \
		width_prec_func.c \
		additional_func.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT = $(LIB_DIR)libft.a
LIBFT_INC := $(LIB_DIR)inc/
LIBFT_FLAGS := -lft -L $(LIB_DIR)

# compilation flags

FLAGS := -Wall -Wextra -Werror -O3

# linking flags

LINK_FLAGS := $(LIBFT_FLAGS)

# header flags

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@ ar rc $(NAME) $(OBJ) libft/obj/standard_func/*.o \
							libft/obj/non_standard_func/*.o \
							libft/obj/lst_func/*.o \
							libft/obj/aditional_func/*.o
		@ ranlib $(NAME)

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
