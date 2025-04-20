/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:49:46 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/20 17:28:21 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <stdint.h>

bool	is_in_shadow(t_config *c, t_light *light,
				t_tuple xpoint, t_multi *thdata)
{
	t_tuple			v;
	double			distance;
	t_tuple			direction;
	t_tuple			offset_point;
	t_intersection	*xs;

	v = tuple_substitute(light->position, xpoint);
	distance = vector_magnitude(v);
	direction = vector_normalize(v);
	offset_point = tuple_add(xpoint, tuple_multiply(direction, ACNE_DECALAGE));
	xs = hit(c, ray_create(offset_point, direction), thdata);
	if (xs)
	{
		if (xs->t < distance)
			return (free(xs), true);
	}
	return (free(xs), false);
}
