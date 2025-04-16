/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:59:28 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 17:28:38 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <pthread.h>
# include <bits/pthreadtypes.h>
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
# include "img.h"

# define EPSILON 0.00001
# define ACNE_DECALAGE 0.0001
# define SCENE_TYPE "A\0C\0L\0sp\0pl\0cy\0co\0"
# define SCENE_TYPE_NUM 7
# define WINH 1000
# define WINW 1000

// errors messages
# define INVALID_FILE "Invalid file : %s\n"
# define ERROR_IN_FILE "Error in scene file : %s\n"
# define INVALID_OBJECT	"Invalid object at line : %d\n"
# define TOO_MANY_ELEMENT "Ambient light, camera \
	and light can only be defined once !\n"
# define INVALID_NUMBER	"Invalid number at line %d\n"

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	DISK,
	CONE
}	t_object_type;

typedef enum e_pattern_type
{
	NONE,
	CHECKERBOARD,
	BUMPMAP
}	t_pattern_type;

typedef struct s_object_node
{
	t_object_type	type;
	void			*obj;
	t_pattern_type	pattern;
	// void			*bump_map;          // Bump map associée à cet objet (si existe)
	// char			*bump_data;         // Données de la bump map
	// int				bump_width;         // Largeur de la bump map
	// int				bump_height;        // Hauteur de la bump map
	// int				bpp;                // Bits par pixel
	// int				size_line;          // Taille d'une ligne de la bump map
	// int				endian;             // Endianness de la bump map
}	t_object_node;

typedef struct s_error
{
	int		line;
	char	*msg;
}	t_error;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersection
{
	double			t;
	t_object_node	*object;
}	t_intersection;

typedef bool	(*t_parsefunc)(void *, char **, int);

typedef struct s_render
{
	int		wall_z;
	double	dist_cam_wall;
	double	fov_rad;
	double	half_view;
	double	wall_size;
	double	image_pixels;
	double	pixel_size;
	double	half;
	t_tuple	forward;
	t_tuple	right;
	t_tuple	up;
	double	world_y;
	double	world_x;
	t_tuple	pixel_offset;
	t_tuple	pixel_world;
	t_tuple	dir;
	t_ray	ray;
	t_tuple	x_point;
	bool	in_shadow;
}	t_render;

typedef struct s_lighting
{
	t_material	m;
	t_light		l;
	t_tuple		p;
	t_tuple		eyev;
	t_tuple		normal_vec;
	bool		in_shadow;
	t_list		*spotlights;
	t_tuple		lightv;
	t_color		light_real_color;
	t_color		ambient;
	double		light_dot_normal;
	t_color		diffuse;
	t_color		specular;
}	t_lighting;

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
	t_img			earth;
	t_parsefunc		*funcs;
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_list			*spotlights;
	t_list			*objects_list;
	int				total_objects;
	t_lighting		l;
	pthread_mutex_t	config_mut;
}	t_config;

typedef struct s_multi
{
	int				idx;
	int				minpx;
	int				maxpx;
	t_config		*config;
	t_render		render;
	pthread_mutex_t	*config_mut;
}	t_multi;

int			clean_exit(t_config *config);
void		install_hooks(t_config *config);

// tests
void		tuples_tests(void);
void		tuples_proj_test(void);
void		test_circle(t_config *c);
void		test_eclairage(t_config *c);
void		test_phong(t_config *c);

// utils
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int			mlx_get_color(t_img *data, int x, int y);
bool		is_in_shadow(t_config *c, t_light *light, t_tuple xpoint, int id, t_multi *thdata);
t_color		lighting(t_lighting *l, t_light *light, t_config *c);
int			color_to_int(t_color color);
t_material	default_material(t_color color);
bool		check_only_valid_float(char **tab, int maxindex);
int			get_obj_id(t_object_node *obj);

// init
t_config	*init_config(int ac, char **av);

// parsing
bool		parse_scene(t_config *c, char *filepath);
bool		parse_sphere(t_config *c, char **infos, int currline);
bool		parse_plan(t_config *c, char **infos, int currline);
bool		parse_cylinder(t_config *c, char **infos, int currline);
bool		parse_cone(t_config *c, char **infos, int currline);
bool		parse_ambient(t_config *c, char **infos, int currline);
bool		parse_light(t_config *c, char **infos, int currline);
bool		parse_camera(t_config *c, char **infos, int currline);

void		print_config(t_config *c);
bool		check_config(t_config *config);
bool		check_colors_error(t_config *config);
bool		null_vec(t_tuple v);
bool		invalid_vec(t_tuple v);
bool		check_vectors(t_config *c);
bool		size_checks(t_config *config);

void		print_ambient(t_ambient_light *a);
void		print_camera(t_camera *c);
void		print_light(t_light *l);
void		print_plane(t_plane *p);
void		print_sphere(t_sphere *s);

// cast
t_sphere	*listptr_to_sphere(t_list *elem);
t_plane		*listptr_to_plane(t_list *elem);
t_cylinder	*listptr_to_cylinder(t_list *elem);

// render
void		render(t_config *c);
int			render_sphere(t_config *c, t_intersection *xs, t_render *render);
int			render_plane(t_config *c, t_intersection *xs, t_render *render);
int			render_cylinder(t_config *c, t_intersection *xs, t_render *render);
int			render_disk(t_config *c, t_intersection *xs, t_render *render);
int			render_cone(t_config *c, t_intersection *xs, t_render *render);


bool		render_multi(t_config *c);

t_pattern_type	pattern_plane_checkerboard(t_tuple *point, t_tuple *vec);
t_pattern_type	pattern_sphere_checkerboard(t_tuple *point, t_tuple *vec);
float		define_intensity(t_pattern_type type);

// texture 
int		get_texture_color_sphere(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n);
int		get_texture_color_plane(t_config *c, t_plane *p, t_tuple *x_point, t_tuple *n);

#endif
