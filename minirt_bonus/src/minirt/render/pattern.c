/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:32:53 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/20 12:34:38 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_pattern_type	pattern_plane_checkerboard(t_tuple *point, t_tuple *vec)
{
	int		u;
	int		v;

	if (fabs(vec->x) >= fabs(vec->y) && fabs(vec->x) >= fabs(vec->z))
	{
		u = (int)floor(point->y);
		v = (int)floor(point->z);
	}
	else if (fabs(vec->y) > fabs(vec->z))
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
	float	x;
	float	y;
	int		u;
	int		v;

	(void)point;
	x = 0.5 + atan2(vec->z, vec->x) / (2 * M_PI);
	y = 0.5 - asin(vec->y) / M_PI;
	u = floor(x * 10);
	v = floor(y * 10);
	if ((u + v) % 2 == 0)
		return (NONE);
	return (CHECKERBOARD);
}

float	define_intensity(t_pattern_type type)
{
	if (type == CHECKERBOARD)
		return (0.1);
	return (1);
}
