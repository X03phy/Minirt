/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:54:49 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 19:28:52 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../libs/libft/include/tuple.h"
# include "minirt.h"

typedef struct s_material
{
	t_tuple	color;
	double ambient;
	double diffuse;
	double specular;
	double shininess;
}	t_material;

typedef struct s_sphere
{
	t_tuple	center;
	double	radius;
	int		color;
	t_tuple	tcolor;
	t_material	material;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	center;
	t_tuple	orientation_vec;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple	center;
	t_tuple	orientation_vec;
	double	diameter;
	double	height;
	int		color;
}	t_cylinder;

#endif
