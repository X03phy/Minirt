/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:46:04 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/17 16:51:30 by maecarva         ###   ########.fr       */
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

static void	init_cone(t_cone_math *cm, t_cone *c, t_ray r)
{
	cm->v = tuple_substitute(r.origin, c->summit);
	cm->cos_theta = cos(c->angle);
	cm->cos2 = cm->cos_theta * cm->cos_theta;
	cm->dv = vector_dot(r.direction, c->orientation_vec);
	cm->vv = vector_dot(cm->v, c->orientation_vec);
	cm->d_dot_d = vector_dot(r.direction, r.direction);
	cm->v_dot_d = vector_dot(cm->v, r.direction);
	cm->v_dot_v = vector_dot(cm->v, cm->v);
}

bool	ray_cone_intersection(t_cone *c, t_ray r, double *x)
{
	double		args[3];
	double		inter[2];
	t_cone_math	cm;

	init_cone(&cm, c, r);
	args[0] = cm.dv * cm.dv - cm.cos2 * cm.d_dot_d;
	args[1] = 2 * (cm.dv * cm.vv - cm.cos2 * cm.v_dot_d);
	args[2] = cm.vv * cm.vv - cm.cos2 * cm.v_dot_v;
	cm.discriminant = pow(args[1], 2.0) - (4 * args[0] * args[2]);
	if (cm.discriminant < 0)
		return (false);
	inter[0] = (-args[1] - sqrt(cm.discriminant)) / (2 * args[0]);
	inter[1] = (-args[1] + sqrt(cm.discriminant)) / (2 * args[0]);
	*x = get_cone_hit(inter);
	cm.hit_point = tuple_add(r.origin, tuple_multiply(r.direction, *x));
	cm.oia = tuple_substitute(cm.hit_point, c->summit);
	cm.proj = vector_dot(cm.oia, c->orientation_vec);
	if (cm.proj < 0 || cm.proj > c->height)
		return (false);
	return (true);
}
