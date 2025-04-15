/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:49:46 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/11 11:57:02 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <stdint.h>

bool	is_in_shadow(t_config *c, t_light *light, t_tuple xpoint, int id)
{
	t_tuple			v;
	double			distance;
	t_tuple			direction;
	t_tuple			offset_point;
	t_intersection	*xs;

	if (id == -1)
		return (false);
	v = tuple_substitute(light->position, xpoint);
	distance = vector_magnitude(v);
	direction = vector_normalize(v);
	offset_point = tuple_add(xpoint, tuple_multiply(direction, ACNE_DECALAGE));
	xs = hit(c, ray_create(offset_point, direction));
	if (xs)
	{
		if (get_obj_id(xs->object) == id)
			return (free(xs), false);
		if (xs->t < distance)
			return (free(xs), true);
	}
	return (free(xs), false);
}
