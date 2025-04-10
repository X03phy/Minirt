/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:23:47 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/10 17:08:06 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

int	render_sphere(t_config *c, t_tuple	x_point, t_intersection *xs, t_ray r, bool in_shadow)
{
	t_tuple normal_vec = vector_normalize(tuple_substitute(x_point, ((t_sphere *)xs->object->obj)->center));
	t_tuple	eyev = tuple_negate(r.direction);
	t_tuple color = lighting(((t_sphere *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
	return (color_to_int(color));
}

int	render_plane(t_config *c, t_tuple	x_point, t_intersection *xs, t_ray r, bool in_shadow)
{
	t_tuple normal_vec = ((t_plane *)xs->object->obj)->orientation_vec;
	t_tuple	eyev = tuple_negate(r.direction);
	t_tuple color = lighting(((t_plane *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
	return (color_to_int(color));
}

int	render_cylinder(t_config *c, t_tuple	x_point, t_intersection *xs, t_ray r, bool in_shadow)
{
	t_cylinder *cylinder;
	cylinder = ((t_cylinder *)xs->object->obj);
	t_tuple oc = tuple_substitute(x_point, cylinder->center);
	double m = vector_dot(oc, cylinder->orientation_vec);
	t_tuple proj = tuple_multiply(cylinder->orientation_vec, m);
	t_tuple normal_vec = vector_normalize(tuple_substitute(oc, proj));
	t_tuple	eyev = tuple_negate(r.direction);
	t_tuple color = lighting(((t_cylinder *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
	return (color_to_int(color));
}

int	render_disk(t_config *c, t_tuple	x_point, t_intersection *xs, t_ray r, bool in_shadow)
{
	t_tuple normal_vec = ((t_disk *)xs->object->obj)->orientation_vec;
	t_tuple	eyev = tuple_negate(r.direction);
	t_tuple color = lighting(((t_disk *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
	return (color_to_int(color));
}
