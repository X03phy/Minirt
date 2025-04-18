/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:50:19 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/18 14:06:10 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

int	get_texture_color_sphere(t_config *c, t_sphere *s,
		t_tuple *x_point, t_tuple *n)
{
	float	x;
	float	y;
	float	u;
	float	v;
	int		colortexture;

	x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	y = 0.5 - asin(n->y) / M_PI;
	u = x * s->texture.imgw + (s->texture.imgw / 4.0);
	v = y * s->texture.imgh;
	colortexture = mlx_get_color(&s->texture, u, v);
	return (colortexture);
	(void)x_point;
	(void)s;
	(void)c;
}

t_tuple	make_tangent(t_tuple *n)
{
	t_tuple	tangent;

	if (fabs(n->x) > fabs(n->y))
		tangent = tuple_create(-n->z, 0, n->x, 0);
	else
		tangent = tuple_create(0, n->z, -n->y, 0);
	return (vector_normalize(tangent));
}

int	get_texture_color_plane(t_config *c, t_plane *p,
		t_tuple *x_point, t_tuple *n)
{
	t_tuple	tangent;
	t_tuple	bitangent;
	t_tuple	delta;
	float	u;
	float	v;

	tangent = make_tangent(n);
	bitangent = vector_cross_product(*n, tangent);
	delta = tuple_substitute(*x_point, p->center);
	u = vector_dot(delta, tangent);
	v = vector_dot(delta, bitangent);
	u = u - floorf(u);
	v = v - floorf(v);
	u = (int)(u * p->texture.imgw);
	v = (int)(v * p->texture.imgh);
	return ((int)mlx_get_color(&p->texture, u, v));
	(void)c;
}
