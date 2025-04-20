/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:56:14 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/20 16:26:00 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

static t_tuple	int_to_normal(int color)
{
	t_tuple	normal;

	normal.x = (color >> 16) & 0xFF;
	normal.y = (color >> 8) & 0xFF;
	normal.z = (color) & 0xFF;
	normal.x = normal.x / 255.0;
	normal.y = normal.y / 255.0;
	normal.z = normal.z / 255.0;
	normal.w = 0;
	return (vector_normalize(normal));
}

t_tuple	get_ref_vector(t_tuple *n)
{
	int	sign;

	if (fabs(n->y) == 1)
	{
		if (n->y < 0)
			sign = -1;
		else
			sign = 1;
		return (vector_create(0, 0, sign));
	}
	return (vector_create(0, 1, 0));
}

int	get_bump_color_sphere(t_sphere *s, t_tuple *n)
{
	float	x;
	float	y;
	float	u;
	float	v;
	int		colorbump;

	x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	y = 0.5 - asin(n->y) / M_PI;
	u = x * s->bump.imgw + (s->bump.imgw / 4.0);
	v = y * s->bump.imgh;
	colorbump = mlx_get_color(&s->bump, u, v);
	return (colorbump);
}

t_tuple	get_bump_normal_sphere(t_tuple *n, t_sphere *s)
{
	t_tuple	c;
	t_tuple	ref_vec;
	t_tuple	t;
	t_tuple	b;
	t_tuple	new_normal;

	c = int_to_normal(get_bump_color_sphere(s, n));
	ref_vec = get_ref_vector(n);
	t = vector_normalize(vector_cross_product(ref_vec, c));
	b = vector_normalize(vector_cross_product(c, t));
	new_normal = vector_create(0, 0, 0);
	new_normal.x = t.x * c.x + b.x * c.y + n->x * c.z;
	new_normal.y = t.y * c.x + b.y * c.y + n->y * c.z;
	new_normal.z = t.z * c.x + b.z * c.y + n->z * c.z;
	return (vector_normalize(new_normal));
}

// tangent space to world: n, normal dans la teture,

// tangent = vec_cross(rev_vec, normal);
// bitan = cross(normal, tangent);
// on a normal

// new_normal = [tan bitan normal] dot normal in txture
