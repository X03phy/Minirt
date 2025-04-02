/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:59:28 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 15:42:24 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libs/libft/include/libft.h"
# include "../libs/gnl/include_gnl/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "keycodes.h"
# include "../libs/libft/include/tuple.h"
# include "../libs/libft/include/matrix.h"
# include "color.h"
# include "objects.h"

# define EPSILON 0.00001
# define PI 3.145926
# define SCENE_TYPE "A\0C\0L\0sp\0pl\0cy\0"
# define SCENE_TYPE_NUM 6

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_len;
	int		endian;
}	t_img;

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

typedef struct s_object_node
{
	t_object_type	type;
	void			*obj;
}	t_object_node;

typedef struct s_ambient_light
{
	double	ratio;
	int		color;
}	t_ambient_light;

typedef struct s_camera
{
	t_tuple	position;
	t_tuple	orientation_vec;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_tuple	position;
	double	brightness;
	int		color;
}	t_light;


typedef bool (*parsefunc)(void *, char **);

typedef struct s_config
{
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	parsefunc		*funcs;
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_light			*light;
	t_list			*objects_list;
}	t_config;

void	clean_exit(t_config *config);
void	install_hooks(t_config *config);

// tests
void	tuples_tests(void);
void	tuples_proj_test(void);
void	test_circle(t_config *c);

// utils
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// init
t_config	*init_config(void);

// parsing
bool	parse_scene(t_config *c, char *filepath);
bool	parse_sphere(t_config *c, char **infos);
bool	parse_plan(t_config *c, char **infos);
bool	parse_cylinder(t_config *c, char **infos);
bool	parse_ambient(t_config *c, char **infos);
bool	parse_light(t_config *c, char **infos);
bool	parse_camera(t_config *c, char **infos);

void	print_config(t_config *c);

#endif
