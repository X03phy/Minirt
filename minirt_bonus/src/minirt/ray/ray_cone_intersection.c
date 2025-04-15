/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:46:04 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/14 14:03:16 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

double	get_cone_hit(double	*intersections)
{
	if (intersections[0] > intersections[1])
		return (intersections[1]);
	return (intersections[0]);
}

bool	ray_cone_intersection(t_cone *c, t_ray r, double *x)
{
	double	args[3];
	double	inter[2];

	t_tuple v = tuple_substitute(r.origin, c->summit); // v = O - C
	double cos_theta = cos(c->angle);
	double cos2 = cos_theta * cos_theta;

	double dv = vector_dot(r.direction, c->orientation_vec);
	double vv = vector_dot(v, c->orientation_vec);
	double d_dot_d = vector_dot(r.direction, r.direction);
	double v_dot_d = vector_dot(v, r.direction);
	double v_dot_v = vector_dot(v, v);

	args[0] = dv * dv - cos2 * d_dot_d;
	args[1] = 2 * (dv * vv - cos2 * v_dot_d);
	args[2] = vv * vv - cos2 * v_dot_v;

	double discriminant = pow(args[1], 2.0) - (4 * args[0] * args[2]);
	if (discriminant < 0)
		return (false);
	inter[0] = (-args[1] - sqrt(discriminant)) / (2 * args[0]);
	inter[1] = (-args[1] + sqrt(discriminant)) / (2 * args[0]);
	*x = get_cone_hit(inter);
	t_tuple hit_point = tuple_add(r.origin, tuple_multiply(r.direction, *x));
	t_tuple oia = tuple_substitute(hit_point, c->summit);
	double proj = vector_dot(oia, c->orientation_vec);

	if (proj < 0 || proj > c->height)
		return (false); // le point n’est pas sur la nappe principale du cône
	return (true);
}
