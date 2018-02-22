# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 16:27:49 by agalavan          #+#    #+#              #
#    Updated: 2017/11/29 16:27:59 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

# project directories

SRC_DIR := ./src/
OBJ_DIR := ./obj/
OBJ_DIR_1 := ./obj/standard_func
OBJ_DIR_2 := ./obj/non_standard_func
OBJ_DIR_3 := ./obj/lst_func
OBJ_DIR_4 := ./obj/aditional_func
INC_DIR := ./inc/

# project source files

SRC :=	standard_func/ft_atoi.c\
		standard_func/ft_bzero.c\
		standard_func/ft_isalnum.c\
		standard_func/ft_isalpha.c\
		standard_func/ft_isascii.c\
		standard_func/ft_isdigit.c\
		standard_func/ft_isprint.c\
		non_standard_func/ft_itoa.c\
		non_standard_func/ft_memalloc.c\
		standard_func/ft_memccpy.c\
		standard_func/ft_memchr.c\
		standard_func/ft_memcmp.c\
		standard_func/ft_memcpy.c\
		non_standard_func/ft_memdel.c\
		standard_func/ft_memmove.c\
		standard_func/ft_memset.c\
		non_standard_func/ft_putchar.c\
		non_standard_func/ft_putchar_fd.c\
		non_standard_func/ft_putendl.c\
		non_standard_func/ft_putendl_fd.c\
		non_standard_func/ft_putnbr.c\
		non_standard_func/ft_putnbr_fd.c\
		non_standard_func/ft_putstr.c\
		non_standard_func/ft_putstr_fd.c\
		standard_func/ft_strcat.c\
		standard_func/ft_strchr.c\
		non_standard_func/ft_strclr.c\
		standard_func/ft_strcmp.c\
		standard_func/ft_strcpy.c\
		non_standard_func/ft_strdel.c\
		standard_func/ft_strdup.c\
		non_standard_func/ft_strequ.c\
		non_standard_func/ft_striter.c\
		non_standard_func/ft_striteri.c\
		non_standard_func/ft_strjoin.c\
		standard_func/ft_strlcat.c\
		standard_func/ft_strlen.c\
		non_standard_func/ft_strmap.c\
		non_standard_func/ft_strmapi.c\
		standard_func/ft_strncat.c\
		standard_func/ft_strncmp.c\
		standard_func/ft_strncpy.c\
		non_standard_func/ft_strnequ.c\
		non_standard_func/ft_strnew.c\
		standard_func/ft_strnstr.c\
		standard_func/ft_strrchr.c\
		non_standard_func/ft_strsplit.c\
		standard_func/ft_strstr.c\
		non_standard_func/ft_strsub.c\
		non_standard_func/ft_strtrim.c\
		standard_func/ft_tolower.c\
		standard_func/ft_toupper.c\
		lst_func/ft_lstadd.c\
		lst_func/ft_lstdel.c\
		lst_func/ft_lstdelone.c\
		lst_func/ft_lstiter.c\
		lst_func/ft_lstmap.c\
		lst_func/ft_lstnew.c\
		aditional_func/ft_swap.c\
		aditional_func/ft_factorial.c\
		aditional_func/ft_power.c\
		aditional_func/ft_sqrt.c\
		aditional_func/ft_is_prime.c\
		aditional_func/ft_itoa_base_u.c\
		aditional_func/ft_intlen_u.c\
		aditional_func/ft_print_utf.c\
		aditional_func/get_next_line.c

# project object files

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# compilation flags

FLAGS = -Wall -Wextra -Werror

# header flags

HEADER_FLAGS := -I $(INC_DIR)

# rules

all: $(NAME)

$(NAME): $(OBJ)
		@ ar rc $(NAME) $(OBJ)
		@ ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@ mkdir $(OBJ_DIR)
		@ mkdir $(OBJ_DIR_1)
		@ mkdir $(OBJ_DIR_2)
		@ mkdir $(OBJ_DIR_3)
		@ mkdir $(OBJ_DIR_4)

$(OBJ_DIR)%.o: %.c
		@ gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

clean:
		@ rm -f $(OBJ)

fclean: clean
		@ rm -f $(NAME)
		@ rm -rf $(OBJ_DIR)

re: fclean all

# special stuff

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
