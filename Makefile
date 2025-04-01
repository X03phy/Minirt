# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:45:30 by ebonutto          #+#    #+#              #
#    Updated: 2025/04/01 17:28:11 by ebonutto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT
CC = cc
CFLAGS = -Werror -Wextra -Wall

SRC_PATH = src/
OBJ_PATH = obj/
INCLUDE = -I include -I $(MINILIBX_PATH) -I $(LIBFT_PATH)

LIBS_PATH = libs

MINILIBX_PATH = $(LIBS_PATH)/minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a

GNL_PATH = $(LIBS_PATH)/gnl
GNL = $(GNL_PATH)/gnl.a

SRC = main.c \
	  hooks.c \

SRCS = $(addprefix src/, $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all: $(NAME)

bonus: all

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(LIBFT):
	make -sC $(LIBFT_PATH)

$(MINILIBX):
	make -sC $(MINILIBX_PATH)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $@  $(OBJS) $(LIBFT) $(MINILIBX) $(INCLUDE) -lm -lX11 -lXext

clean:
	make -sC $(LIBFT_PATH) clean
	make -sC $(MINILIBX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -sC $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus