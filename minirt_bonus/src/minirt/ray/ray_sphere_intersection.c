/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:14 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 11:43:53 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

double	get_sphere_hit(double	*intersections)
{
	if (intersections[0] > intersections[1])
		return (intersections[1]);
	return (intersections[0]);
}

// args : 0 = a, 1 = b, 2 = c
bool	ray_sphere_intersection(t_sphere *s, t_ray r, double *x)
{
	double	inter[2];
	double	args[3];
	double	discriminant;
	t_tuple	sphere_to_ray;

	sphere_to_ray = tuple_substitute(r.origin, s->center);
	args[0] = vector_dot(r.direction, r.direction);
	args[1] = 2 * vector_dot(r.direction, sphere_to_ray);
	args[2] = vector_dot(sphere_to_ray, sphere_to_ray) - pow(s->radius, 2.0);
	discriminant = pow(args[1], 2.0) - (4 * args[0] * args[2]);
	if (discriminant < 0)
		return (false);
	inter[0] = (-args[1] - sqrt(discriminant)) / (2 * args[0]);
	inter[1] = (-args[1] + sqrt(discriminant)) / (2 * args[0]);
	*x = get_sphere_hit(inter);
	return (true);
}
