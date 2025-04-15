/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:48:27 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/15 13:47:48 by ebonutto         ###   ########.fr       */
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

t_pattern_type	pattern_checkerboard(t_tuple *point)
{
	if (((int)floor(point->x)+(int)floor(point->y)) % 2 == 0)
		return (NONE);
	return (CHECKERBOARD);
}

float	define_intensity(t_pattern_type type)
{
	if (type == NONE)
		return (1.0);
	return (0.8);
}
