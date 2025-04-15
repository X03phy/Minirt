/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:44:05 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/08 13:55:23 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

bool	ray_plane_intersection(t_plane *p, t_ray r, double *x)
{
	double	dotp;

	dotp = vector_dot(r.direction, p->orientation_vec);
	if (fabs(dotp) < EPSILON)
		return (false);
	*x = vector_dot(tuple_substitute(p->center, r.origin),
			p->orientation_vec) / dotp;
	if (*x < 0)
		return (false);
	return (true);
}
