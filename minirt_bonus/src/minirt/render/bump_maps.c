/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:56:14 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/17 17:08:10 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

t_tuple	get_bump_color_sphere(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n)
{
	t_tuple color;

	float x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	float y = 0.5 - asin(n->y) / M_PI;
	float u = x * s->bump.imgw + (s->bump.imgw / 4.0);
	float v = y * s->bump.imgh;
	int	colorbp = mlx_get_color(&s->bump, u, v);
	color.x = (colorbp >> 16) & 0xFF;
	color.x = (colorbp >> 16) & 0xFF;
	color.x = (colorbp >> 16) & 0xFF;

	// int	bumpedtexture = 0;
	//
	// if (s->bump_name)
	// {
	// 	bumpedtexture = mlx_get_color(&s->bump, u, v);
	// 	return (handle_colors(colortexture, bumpedtexture));
	// }
	return (colortexture);
	(void)x_point;
	(void)s;
	(void)c;
}
