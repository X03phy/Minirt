/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:23:47 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/20 15:24:04 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <pthread.h>

int	render_cylinder(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	oc;
	t_tuple	proj;
	t_tuple	color;
	t_list	*tmp;

	color = tuple_create(0, 0, 0, 0);
	tmp = c->spotlights->next;
	oc = tuple_substitute(render->x_point,
			((t_cylinder *)xs->object->obj)->center);
	proj = tuple_multiply(((t_cylinder *)xs->object->obj)->orientation_vec,
			vector_dot(oc, ((t_cylinder *)xs->object->obj)->orientation_vec));
	ft_bzero(&c->l, sizeof(t_lighting));
	c->l.normal_vec = vector_normalize(tuple_substitute(oc, proj));
	c->l.eyev = tuple_negate(render->ray.direction);
	c->l.p = render->x_point;
	c->l.m = ((t_cylinder *)xs->object->obj)->material;
	c->l.spotlights = c->spotlights;
	c->l.in_shadow = render->in_shadow;
	color = lighting(&c->l, (t_light *)c->spotlights->content, c);
	while (tmp)
	{
		color = tuple_add(color, lighting(&c->l, (t_light *)tmp->content, c));
		tmp = tmp->next;
	}
	return (color_to_int(color));
}

int	render_disk(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	color;
	t_list	*tmp;

	color = tuple_create(0, 0, 0, 0);
	tmp = c->spotlights;
	ft_bzero(&c->l, sizeof(t_lighting));
	c->l.normal_vec = ((t_disk *)xs->object->obj)->orientation_vec;
	c->l.eyev = tuple_negate(render->ray.direction);
	c->l.p = render->x_point;
	c->l.m = ((t_disk *)xs->object->obj)->material;
	c->l.spotlights = c->spotlights;
	c->l.in_shadow = render->in_shadow;
	color = lighting(&c->l, (t_light *)tmp->content, c);
	tmp = tmp->next;
	while (tmp)
	{
		color = tuple_add(color, lighting(&c->l, (t_light *)tmp->content, c));
		tmp = tmp->next;
	}
	return (color_to_int(color));
}

t_tuple	cone_normal_at(t_cone *cone, t_tuple point)
{
	t_tuple	apex_to_point;
	double	proj_len;
	t_tuple	proj;
	t_tuple	ortho;
	t_tuple	n;

	apex_to_point = tuple_substitute(point, cone->summit);
	proj_len = vector_dot(apex_to_point, cone->orientation_vec);
	proj = tuple_multiply(cone->orientation_vec, proj_len);
	ortho = tuple_substitute(apex_to_point, proj);
	n = vector_normalize(tuple_substitute(ortho,
				tuple_multiply(cone->orientation_vec,
					proj_len * pow(tan(cone->angle), 2))));
	if (proj_len < 0)
		n = tuple_negate(n);
	return (n);
}

int	render_cone(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	color;
	t_list	*tmp;

	ft_bzero(&c->l, sizeof(t_lighting));
	color = tuple_create(0, 0, 0, 0);
	tmp = c->spotlights;
	c->l.normal_vec = cone_normal_at((t_cone *)xs->object->obj,
			render->x_point);
	c->l.eyev = tuple_negate(render->ray.direction);
	c->l.p = render->x_point;
	c->l.m = ((t_cone *)xs->object->obj)->material;
	c->l.spotlights = c->spotlights;
	c->l.in_shadow = render->in_shadow;
	color = lighting(&c->l, (t_light *)tmp->content, c);
	tmp = tmp->next;
	while (tmp)
	{
		color = tuple_add(color, lighting(&c->l, (t_light *)tmp->content, c));
		tmp = tmp->next;
	}
	return (color_to_int(color));
}
