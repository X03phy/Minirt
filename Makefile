# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:45:30 by ebonutto          #+#    #+#              #
#    Updated: 2025/04/04 17:51:05 by maecarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CC = cc
CFLAGS = -Werror -Wextra -Wall -g -O3 -flto -ffast-math -march=native -pipe

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
	  			minirt/parsing/object_parsers/cylinder.c \
	  			minirt/parsing/object_parsers/plan.c \
	  			minirt/parsing/object_parsers/sphere.c \
	  			minirt/parsing/object_parsers/ambient.c \
	  			minirt/parsing/object_parsers/camera.c \
	  			minirt/parsing/object_parsers/light.c \
				minirt/parsing/init_config.c \
				minirt/parsing/print_config.c \
				minirt/parsing/checks.c

SRCTESTS = minirt/tests/circle.c \
		   minirt/tests/eclairage.c \
		   minirt/tests/multiple_spheres.c \
		   minirt/tests/sphere_phong.c

SRC_RAY = minirt/ray/ray_create.c \
		  minirt/ray/ray_position.c \
		  minirt/ray/ray_print.c \
		  minirt/ray/ray_sphere_intersection.c \
		  minirt/ray/ray_transform.c \
		  minirt/ray/lighting.c

SRCUTILS = minirt/mlx_utils/utils1.c

SRC = 	$(SRCPARSING) \
		$(SRCTESTS) \
		$(SRCUTILS) \
		$(SRC_RAY) \
		main.c \
	  	hooks.c \
	  	utils.c

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
