# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:45:30 by ebonutto          #+#    #+#              #
#    Updated: 2025/04/02 12:30:31 by maecarva         ###   ########.fr        #
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

SRCPARSING =	minirt/parsing/parsing.c \
	  			minirt/parsing/cylinder.c \
	  			minirt/parsing/plan.c \
	  			minirt/parsing/sphere.c \
				minirt/parsing/init_config.c

SRCTESTS = minirt/tests/circle.c

SRCUTILS = minirt/mlx_utils/utils1.c

SRC = 	$(SRCPARSING) \
		$(SRCTESTS) \
		$(SRCUTILS) \
		main.c \
	  	hooks.c \

SRCS = $(addprefix src/, $(SRC))
OBJS = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

bonus: all

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@echo "Compiling " $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(GNL):
	@make -sC $(GNL_PATH)

$(MINILIBX):
	@make -sC $(MINILIBX_PATH)

$(NAME): $(LIBFT) $(GNL) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) -o $@  $(OBJS) $(GNL) $(LIBFT) $(MINILIBX) $(INCLUDE) -lm -lX11 -lXext
	@echo "Creating" $(NAME)

clean:
	make -sC $(LIBFT_PATH) clean
	make -sC $(GNL_PATH) clean
	make -sC $(MINILIBX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -sC $(GNL_PATH) fclean
	make -sC $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
