/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:50:19 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/16 18:15:14 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

int	get_texture_color_sphere(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n)
{
	float x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	float y = 0.5 - asin(n->y) / M_PI;
	float u = x * 1000;
	float v = y * 500;
	return ((int)mlx_get_color(&s->texture, u, v));
	(void)x_point;
	(void)s;
	(void)c;
}

int	get_texture_color_plane(t_config *c, t_plane *p, t_tuple *x_point, t_tuple *n)
{
   (void)p;
   (void)x_point;
   (void)n;
   float u = x_point->x - floor(x_point->x);
   float v = x_point->z - floor(x_point->z);
   int tex_u = u * 1000;
   int tex_v = v * 500;
   return ((int)mlx_get_color(&c->earth, tex_u, tex_v));
}
