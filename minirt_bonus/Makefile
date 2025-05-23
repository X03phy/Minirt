# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:45:30 by ebonutto          #+#    #+#              #
#    Updated: 2025/04/20 15:22:15 by ebonutto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CC = cc
CFLAGS = -Werror -Wextra -Wall -g3 -pthread #-fsanitize=address,null
# CFLAGS = -Werror -Wextra -Wall -g3 -pthread -fsanitize=address,null

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
				minirt/parsing/object_parsers/cone.c \
	  			minirt/parsing/object_parsers/plan.c \
	  			minirt/parsing/object_parsers/sphere.c \
	  			minirt/parsing/object_parsers/ambient.c \
	  			minirt/parsing/object_parsers/camera.c \
	  			minirt/parsing/object_parsers/light.c \
	  			minirt/parsing/object_parsers/parser_utils.c \
				minirt/parsing/init_config.c \
				minirt/parsing/print_config.c \
				minirt/parsing/print_config2.c \
				minirt/parsing/print_config3.c \
				minirt/parsing/checks/checks.c \
				minirt/parsing/checks/vec_checks.c \
				minirt/parsing/checks/size_checks.c \
				minirt/parsing/checks/color_checks.c

SRC_RAY = minirt/ray/ray_create.c \
		  minirt/ray/ray_position.c \
		  minirt/ray/ray_print.c \
		  minirt/ray/ray_cone_intersection.c \
		  minirt/ray/ray_sphere_intersection.c \
		  minirt/ray/ray_plane_intersection.c \
		  minirt/ray/ray_transform.c \
		  minirt/ray/lighting.c \
		  minirt/ray/ray_cylinder_intersection.c \
		  minirt/ray/ray_disk_intersection.c

SRC_HIT = minirt/intersections/hit.c \
		  minirt/intersections/hit2.c

SRCMLXUTILS = minirt/mlx_utils/utils1.c

SRCUTILS = minirt/utils/utils.c

SRCRENDER = minirt/render/render.c \
			minirt/render/render_obj.c \
			minirt/render/render_obj2.c \
			minirt/render/pattern.c \
			minirt/render/textures.c \
			minirt/render/bump_maps.c \
			minirt/render/multi/render_multi.c

SRCHOOKS = minirt/hooks/gen_ray.c \
		   minirt/hooks/move.c

SRC = 	$(SRCPARSING) \
		$(SRCMLXUTILS) \
		$(SRCUTILS) \
		$(SRC_RAY) \
		$(SRC_HIT) \
		$(SRCRENDER) \
		$(SRCHOOKS) \
		main.c \
	  	hooks.c \
	  	clean.c \

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
