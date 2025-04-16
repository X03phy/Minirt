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

int	get_texture_color(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n)
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

