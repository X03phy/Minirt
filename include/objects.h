/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:54:49 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 11:59:47 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../libs/libft/include/tuple.h"
# include "minirt.h"

typedef struct s_sphere
{
	t_tuple	center;
	double	radius;
	int		color;
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

typedef struct s_intersection
{
	double			t;
	t_object_node		*object;
}	t_intersection;

#endif
