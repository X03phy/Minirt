/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:14 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 09:40:57 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

double	*ray_sphere_intersection(t_sphere s, t_ray r)
{
	double	*inter;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	t_tuple	sphere_to_ray = sub_tuples(r.origin, s.center);

	inter = ft_calloc(sizeof(double), 2);
	if (!inter)
		return (NULL);

	a = dot_tuple(r.direction, r.direction);
	b = 2 * dot_tuple(r.direction, sphere_to_ray);
	c = dot_tuple(sphere_to_ray, sphere_to_ray) - pow(s.radius, 2.0);
	discriminant = pow(b, 2.0) - (4 * a * c);

	if (discriminant < 0)
	{
		return (free(inter), NULL);
	}

	inter[0] = (-b - sqrt(discriminant)) / (2 * a);
	inter[1] = (-b + sqrt(discriminant)) / (2 * a);
	return (inter);
}
