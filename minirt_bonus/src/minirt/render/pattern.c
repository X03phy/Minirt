/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:48:27 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/16 12:11:39 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

// t_pattern_type	pattern_checkerboard(t_tuple *point)
// {
// 	(void)point;
// 	if (((int)round(point->x + point->y + point->z)) % 2 == 0)
// 		return (NONE);
// 	return (CHECKERBOARD);
// }

t_pattern_type	pattern_plane_checkerboard(t_tuple *point, t_tuple *vec)
{
	int u, v;

	t_tuple n = *vec;

	if (fabs(n.x) >= fabs(n.y) && fabs(n.x) >= fabs(n.z))
	{
		u = (int)floor(point->y);
		v = (int)floor(point->z);
	}
	else if (fabs(n.y) > fabs(n.z))
	{
		u = (int)floor(point->x);
		v = (int)floor(point->z);
	}
	else
	{
		u = (int)floor(point->x);
		v = (int)floor(point->y);
	}
	if ((u + v) % 2 == 0)
		return (NONE);
	return (CHECKERBOARD);
}

t_pattern_type	pattern_sphere_checkerboard(t_tuple *point, t_tuple *vec)
{
	(void)point;
	float x = 0.5 + atan2(vec->z, vec->x) / (2 * M_PI);
	float y = 0.5 - asin(vec->y) / M_PI;
	int u = floor(x * 10);
	int v = floor(y * 10);
	if ((u + v) % 2 == 0)
		return (NONE);
	return (CHECKERBOARD);
}

int	pattern_color(t_object_node *obj, int color)
{
	float	intensity;

	if (obj->pattern == CHECKERBOARD)
	{
		intensity = 0.8;
	}
}
