/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:59:28 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 11:04:27 by maecarva         ###   ########.fr       */
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

// errors messages
# define INVALID_FILE "Invalid file : %s\n"
# define ERROR_IN_FILE "Error in scene file : %s\n"
# define INVALID_OBJECT	"Invalid object at line : %d\n"
# define TOO_MANY_ELEMENT "Ambient light, camera and light can only be defined once !\n"
# define INVALID_NUMBER	"Invalid number at line %d\n"

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

typedef struct s_error
{
	int		line;
	char	*msg;
}	t_error;

typedef bool (*parsefunc)(void *, char **, int);

typedef struct s_config
{
	int				win_height;
	int				win_width;
	int				ac;
	char			**av;
	t_error			err;
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	parsefunc		*funcs;
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_light			*light;
	t_list			*objects_list;
	int				total_objects;
}	t_config;

typedef struct s_intersection
{
	double			t;
	t_object_node	*object;
}	t_intersection;

typedef struct s_intersection2
{
	double			t1;
	double			t2;
	t_object_node	*object;
}	t_intersection2;


void	clean_exit(t_config *config);
void	install_hooks(t_config *config);

// tests
void	tuples_tests(void);
void	tuples_proj_test(void);
void	test_circle(t_config *c);
void	test_eclairage(t_config *c);
void	test_phong(t_config *c);

// utils
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_color		lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv, t_config *c);
int			color_to_int(t_color color);
t_material	default_material(t_color color);
bool		check_only_valid_float(char **tab);

// init
t_config	*init_config(int ac, char **av);

// parsing
bool	parse_scene(t_config *c, char *filepath);
bool	parse_sphere(t_config *c, char **infos, int currline);
bool	parse_plan(t_config *c, char **infos, int currline);
bool	parse_cylinder(t_config *c, char **infos, int currline);
bool	parse_ambient(t_config *c, char **infos, int currline);
bool	parse_light(t_config *c, char **infos, int currline);
bool	parse_camera(t_config *c, char **infos, int currline);

void	print_config(t_config *c);
bool	check_config(t_config *config);

// cast
t_sphere	*listptr_to_sphere(t_list *elem);
t_plane		*listptr_to_plane(t_list *elem);
t_cylinder	*listptr_to_cylinder(t_list *elem);

#endif
