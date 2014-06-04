# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfrey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/30 11:03:46 by rfrey             #+#    #+#              #
#    Updated: 2014/01/17 22:51:44 by rfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2
NAME = wolf3d
PATH_OBJ = obj
PATH_SRC = src
PATH_INC = inc
PATH_LIBFT = libft
LIBFT = libft.a
PATH_LIBFT_INC = $(PATH_LIBFT)/includes
SRC = main.c handle.c map.c trigo.c render.c inter.c inter2.c move.c image.c \
free.c move2.c texture.c floor.c
OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))
MLX = -L /usr/X11/lib -lmlx -lXext -lX11
X = /usr/X11/include/X11

all : $(NAME)

$(NAME) : $(PATH_LIBFT)/$(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PATH_LIBFT)/$(LIBFT) -o $@ $(MLX)
	@echo " done !"

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@echo -n .
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(PATH_INC)/ -I $(PATH_LIBFT_INC)/ -I $(X)/

$(PATH_LIBFT)/$(LIBFT) : $(PATH_LIBFT)/Makefile
	@cd $(PATH_LIBFT)/ && $(MAKE)

clean :
	@rm -f $(OBJ)
	@cd $(PATH_LIBFT) && $(MAKE) $@

fclean : clean
	@rm -f $(NAME)
	@rm -f $(PATH_LIBFT)/$(LIBFT)

re : fclean all

.PHONY: clean fclean
