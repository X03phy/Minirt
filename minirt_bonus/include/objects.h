/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:54:49 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 16:46:35 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../libs/libft/include/tuple.h"
# include "color.h"
# include "img.h"

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_sphere
{
	int			id;
	t_tuple		center;
	double		radius;
	t_color		color;
	t_material	material;
	bool		checked;
	bool		textured;
	char		*texture_name;
	t_img		texture;
	bool		bumped;
	char		*bump_name;
	t_img		bump;
}	t_sphere;

typedef struct s_plane
{
	int			id;
	t_tuple		center;
	t_tuple		orientation_vec;
	t_color		color;
	t_material	material;
	bool		checked;
	bool		textured;
	char		*texture_name;
	t_img		texture;
	bool		bumped;
	char		*bump_name;
	t_img		bump;
}	t_plane;

typedef struct s_disk
{
	int			id;
	t_tuple		center;
	double		radius;
	t_tuple		orientation_vec;
	t_color		color;
	t_material	material;
}	t_disk;

typedef struct s_cylinder
{
	int			id;
	t_tuple		center;
	t_tuple		orientation_vec;
	double		diameter;
	double		height;
	t_color		color;
	t_material	material;
}	t_cylinder;

typedef struct s_cone {
	int			id;
	t_tuple		summit;
	t_tuple 	orientation_vec;
	double		angle;
	double		height;
	t_color		color;
	t_material	material;
}	t_cone;

typedef struct s_ambient_light
{
	double	ratio;
	t_color	color;
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
	t_color	color;
}	t_light;

#endif


