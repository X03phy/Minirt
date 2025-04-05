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

bool	ray_sphere_intersection(t_sphere *s, t_ray r, double *x)
{
	double	inter[2];
	double	a;
	double	b;
	double	c;
	double	discriminant;

	t_tuple	sphere_to_ray = tuple_substitute(r.origin, s->center);

	a = vector_dot(r.direction, r.direction);
	b = 2 * vector_dot(r.direction, sphere_to_ray);
	c = vector_dot(sphere_to_ray, sphere_to_ray) - pow(s->radius, 2.0);
	discriminant = pow(b, 2.0) - (4 * a * c);

	if (discriminant < 0)
		return (false);
	inter[0] = (-b - sqrt(discriminant)) / (2 * a);
	inter[1] = (-b + sqrt(discriminant)) / (2 * a);
	*x = get_sphere_hit(inter);
	return (true);
}
