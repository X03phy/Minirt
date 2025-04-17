/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:50:19 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/16 18:31:29 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

int	get_texture_color_sphere(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n)
{
	float x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	float y = 0.5 - asin(n->y) / M_PI;
	float u = x * s->texture.imgw;
	float v = y * s->texture.imgh;
	return ((int)mlx_get_color(&s->texture, u, v));
	(void)x_point;
	(void)s;
	(void)c;
}

// int	get_texture_color_plane(t_config *c, t_plane *p, t_tuple *x_point, t_tuple *n)
// {
//    (void)p;
//    (void)x_point;
//    (void)n;
//    (void)c;
//    float u = x_point->x - floor(x_point->x);
//    float v = x_point->z - floor(x_point->z);
//    int tex_u = u * 1000;
//    int tex_v = v * 500;
//    return ((int)mlx_get_color(&p->texture, tex_u, tex_v));
// }

int	get_texture_color_plane(t_config *c, t_plane *p, t_tuple *x_point, t_tuple *n)
{
	int u, v;

	if (fabs(n->x) >= fabs(n->y) && fabs(n->x) >= fabs(n->z))
	{
		// u = (int)floor(x_point->y);
		// v = (int)floor(x_point->z);
		u = (int)x_point->y - floor(x_point->y);
		v = (int)x_point->z - floor(x_point->z);
	}
	else if (fabs(n->y) > fabs(n->z))
	{
		u = (int)x_point->x - floor(x_point->x);
		v = (int)x_point->z - floor(x_point->z);
	}
	else
	{
		// u = (int)floor(x_point->x);
		// v = (int)floor(x_point->y);
		u = (int)x_point->x - floor(x_point->x);
		v = (int)x_point->y - floor(x_point->y);
	}
	int tex_u = u * p->texture.imgw;
	int tex_v = v * p->texture.imgh;
	return ((int)mlx_get_color(&p->texture, tex_u, tex_v));
	(void)c;
}
