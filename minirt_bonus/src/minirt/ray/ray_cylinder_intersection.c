/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:29:52 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/08 13:33:19 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

static bool	get_inter(double discriminant, double *inter, double *args)
{
	if (discriminant < 0)
		return (false);
	else if (discriminant < EPSILON)
	{
		inter[0] = (-args[1]) / (2 * args[0]);
		inter[1] = inter[0];
	}
	else
	{
		inter[0] = (-args[1] - sqrt(discriminant)) / (2 * args[0]);
		inter[1] = (-args[1] + sqrt(discriminant)) / (2 * args[0]);
	}
	return (true);
}

// args : 0 = a, 1 = b, 2 = c
// dotv : 0 = d_dot_v, 1 = x_dot_v
static bool	resolve(double *inter, t_ray ray, t_tuple X, t_cylinder *cylinder)
{
	double	args[3];
	double	discriminant;
	double	d_dot_v;
	double	x_dot_v;

	d_dot_v = vector_dot(ray.direction, cylinder->orientation_vec);
	x_dot_v = vector_dot(X, cylinder->orientation_vec);
	args[0] = 1 - pow(d_dot_v, 2.0);
	if (fabs(args[0]) < EPSILON)
		return (false);
	args[1] = 2.0 * (vector_dot(ray.direction, X) - d_dot_v * x_dot_v);
	args[2] = vector_dot(X, X) - pow(x_dot_v, 2.0)
		- pow((cylinder->diameter / 2), 2.0);
	discriminant = pow(args[1], 2.0) - (4 * args[0] * args[2]);
	return (get_inter(discriminant, inter, args));
}

static bool	get_candidate(double *inter, t_cylinder *cylinder,
				t_ray ray, double *x)
{
	double	t_candidate;
	t_tuple	hit_point;
	t_tuple	from_center;
	double	projection;

	t_candidate = fmin(inter[0], inter[1]);
	hit_point = tuple_add(ray.origin,
			tuple_multiply(ray.direction, t_candidate));
	from_center = tuple_substitute(hit_point, cylinder->center);
	projection = vector_dot(from_center, cylinder->orientation_vec);
	if (projection < -cylinder->height / 2.0
		|| projection > cylinder->height / 2.0)
		return (false);
	*x = t_candidate;
	return (true);
}

bool	ray_cylinder_intersection(t_cylinder *cylinder, t_ray ray, double *x)
{
	double	inter[2];
	t_tuple	x_point;

	x_point = tuple_substitute(ray.origin, cylinder->center);
	if (resolve(inter, ray, x_point, cylinder) == false)
		return (false);
	return (get_candidate(inter, cylinder, ray, x));
}
