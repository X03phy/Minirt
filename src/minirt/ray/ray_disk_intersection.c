/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_disk_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:11:02 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/08 16:08:33 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

bool	ray_disk_intersection(t_disk *d, t_ray r, double *x)
{
	double	dotp;

	dotp = vector_dot(r.direction, d->orientation_vec);
	if (fabs(dotp) < EPSILON)
		return (false);
	*x = vector_dot(tuple_substitute(d->center, r.origin), d->orientation_vec) / dotp;
	if (*x < 0)  // correspond au t trouve
		return (false);
	t_tuple	hit_point = tuple_add(tuple_multiply(r.direction, *x), r.origin); 
	t_tuple	v = tuple_substitute(hit_point, d->center);
	double	dist2 = vector_dot(v, v);
	return (dist2 <= pow(d->radius, 2));         // on ragrde que le carre car sqqrt est trop lent
}
