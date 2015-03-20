# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2015/03/07 14:16:57 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
PATH_SRC = ./src/
PATH_BUILT = ./builtins/
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpadded -Ofast -I $(PATH_INC)
# CFLAGS = -Ofast -I $(PATH_INC) -g
LIBS = -L libft/ -lft

HEAD = $(PATH_SRC)ft_sh1.h

SRC =	main.c \
		sh_loop.c \
		sh_parse.c \
		sh_files.c \
		sh_helper.c \
		sh_signal.c \
		ft_error.c


BUILT = sh_builtin_cd.c \
		sh_builtin_env.c \
		sh_builtin_setenv.c \
		sh_builtin_unsetenv.c \
		sh_builtin_clear.c \
		sh_builtin_exit.c

OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))
OBJ_BUILT = $(addprefix $(PATH_BUILT), $(BUILT:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_BUILT) $(HEAD)
	make -C libft/
	$(CC) $(OBJ) $(OBJ_BUILT) -o $(NAME) $(LIBS)


.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ) $(OBJ_BUILT)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

debug: $(OBJ) $(OBJ_BUILT) $(HEAD)
	make -C libft/
	$(CC) $(OBJ) $(OBJ_BUILT) -o $(NAME) $(LIBS) -g
