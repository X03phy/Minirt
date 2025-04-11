/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:23:47 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 14:21:01 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

int	render_sphere(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	normal_vec;
	t_tuple	eyev;
	t_tuple	color;

	normal_vec = vector_normalize(tuple_substitute(render->x_point,
				((t_sphere *)xs->object->obj)->center));
	eyev = tuple_negate(render->ray.direction);
	color = lighting(((t_sphere *)xs->object->obj)->material,
			*c->light, render->x_point, eyev, normal_vec, c, render->in_shadow);
	return (color_to_int(color));
}

int	render_plane(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	normal_vec;
	t_tuple	eyev;
	t_tuple	color;

	normal_vec = ((t_plane *)xs->object->obj)->orientation_vec;
	eyev = tuple_negate(render->ray.direction);
	color = lighting(((t_plane *)xs->object->obj)->material,
			*c->light, render->x_point, eyev, normal_vec, c, render->in_shadow);
	return (color_to_int(color));
}

int	render_cylinder(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	oc;
	t_tuple	proj;
	t_tuple	normal_vec;
	t_tuple	eyev;
	t_tuple	color;

	oc = tuple_substitute(render->x_point,
			((t_cylinder *)xs->object->obj)->center);
	proj = tuple_multiply(((t_cylinder *)xs->object->obj)->orientation_vec,
			vector_dot(oc, ((t_cylinder *)xs->object->obj)->orientation_vec));
	normal_vec = vector_normalize(tuple_substitute(oc, proj));
	eyev = tuple_negate(render->ray.direction);
	color = lighting(((t_cylinder *)xs->object->obj)->material,
			*c->light, render->x_point, eyev, normal_vec, c, render->in_shadow);
	return (color_to_int(color));
}

int	render_disk(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	normal_vec;
	t_tuple	eyev;
	t_tuple	color;

	normal_vec = ((t_disk *)xs->object->obj)->orientation_vec;
	eyev = tuple_negate(render->ray.direction);
	color = lighting(((t_disk *)xs->object->obj)->material,
			*c->light, render->x_point, eyev, normal_vec, c, render->in_shadow);
	return (color_to_int(color));
}
