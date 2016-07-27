# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 09:49:24 by scaussin          #+#    #+#              #
#    Updated: 2014/06/23 17:38:59 by scaussin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			42sh

CC =			gcc -g $(FLAGS) $(INCLUDES)

LIBFT =			-L./libft -lft -ltermcap
LIB =			./libft/libft.a

INCLUDES =		-I./includes -I./libft/includes

SRC =			src/ft_built_util.c \
				src/ft_builtin.c \
				src/ft_builtin2.c \
				src/ft_cd.c \
				src/ft_cd2.c \
				src/ft_env.c \
				src/ft_exec.c \
				src/ft_open_files.c \
				src/ft_sh2.c \
				src/ft_sh2_utilities.c \
				src/ft_utilities.c \
				src/main.c \
				src/parsing_split_str.c \
				src/parsing.c \
				src/parsing_add_link.c \
				src/parsing_check_error.c \
				src/parsing_tools.c \
				src/prompt.c \
				src/parsing_split_logic_opp.c \
				src/parsing_logic_opp.c \
				src/parsing_rplc_var_env.c

OBJ =			$(SRC:.c=.o)

FLAGS =			-Wall -Wextra -Werror

all:			$(LIB) $(NAME)

$(LIB):
				@echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				@echo "\033[36m[libft]\033[0m Building libft... " | tr -d '\n'
				Make -C libft

$(NAME):		$(OBJ)
				@echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				@echo "\033[36m[$(NAME)]\033[0m " | tr -d '\n'
				@echo "Building $(NAME)... " | tr -d '\n'
				$(CC) -o $(NAME) $(OBJ) $(LIBFT)
				@echo "\033[32m   -> \033[0m" | tr -d '\n'
				@echo "\033[36m$(NAME) \033[0m\033[32mcreated\033[0m"

clean:
				Make -C libft clean
				@echo "\033[31m[clean] " | tr -d '\n'
				@echo "\033[36m[$(NAME)]\033[0m Remove ofiles"
				rm -f $(OBJ)

fclean:
				Make -C libft fclean
				rm -f $(OBJ)
				rm -f $(NAME)
				@echo "\033[31m[fclean] \033[36m[$(NAME)]\033[0m" | tr -d '\n'
				@echo " Remove ofiles & $(NAME)"

re:				fclean all

.PHONY:			all clean re fclean
.SILENT:

%.o:			%.c
				$(CC) -c $< -o $@
