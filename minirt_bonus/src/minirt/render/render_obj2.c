/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:21:13 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/20 17:47:15 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <pthread.h>

static void	render_sphere_norme(t_config *c, t_render *render,
				t_color *color, t_intersection *xs)
{
	float	intensity;
	t_list	*tmp;

	tmp = c->spotlights;
	intensity = 1.0;
	c->l.spotlights = c->spotlights;
	c->l.in_shadow = render->in_shadow;
	*color = lighting(&c->l, (t_light *)tmp->content, c);
	tmp = tmp->next;
	while (tmp)
	{
		*color = tuple_add(*color, lighting(&c->l, (t_light *)tmp->content, c));
		tmp = tmp->next;
	}
	if (((t_sphere *)xs->object->obj)->checked == true)
	{
		xs->object->pattern = pattern_sphere_checkerboard(&(render->x_point),
				&(c->l.normal_vec));
		intensity = define_intensity(xs->object->pattern);
	}
	*color = tuple_multiply(*color, intensity);
}

int	render_sphere(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	color;

	color = tuple_create(0, 0, 0, 0);
	ft_bzero(&c->l, sizeof(t_lighting));
	c->l.normal_vec = vector_normalize(tuple_substitute(render->x_point,
				((t_sphere *)xs->object->obj)->center));
	c->l.eyev = tuple_negate(render->ray.direction);
	c->l.p = render->x_point;
	c->l.m = ((t_sphere *)xs->object->obj)->material;
	if (((t_sphere *)xs->object->obj)->textured == true)
	{
		c->l.m.color = int_to_color(get_texture_color_sphere(c,
					((t_sphere *)xs->object->obj), &render->x_point,
					&(c->l.normal_vec)));
		if (((t_sphere *)xs->object->obj)->bumped == true)
			c->l.normal_vec = get_bump_normal_sphere(&(c->l.normal_vec),
					((t_sphere *)xs->object->obj));
	}
	render_sphere_norme(c, render, &color, xs);
	return (color_to_int(color));
}

static void	render_plane_norme(t_config *c, t_render *render,
		t_intersection *xs)
{
	ft_bzero(&c->l, sizeof(t_lighting));
	c->l.normal_vec = ((t_plane *)xs->object->obj)->orientation_vec;
	c->l.eyev = tuple_negate(render->ray.direction);
	c->l.p = render->x_point;
	c->l.m = ((t_plane *)xs->object->obj)->material;
	if (((t_plane *)xs->object->obj)->textured == true)
		c->l.m.color = int_to_color(get_texture_color_plane(c,
					((t_plane *)xs->object->obj), &render->x_point,
					&(c->l.normal_vec)));
	c->l.spotlights = c->spotlights;
	c->l.in_shadow = render->in_shadow;
}

int	render_plane(t_config *c, t_intersection *xs, t_render *render)
{
	t_tuple	color;
	float	intensity;
	t_list	*tmp;

	intensity = 1.0;
	color = tuple_create(0, 0, 0, 0);
	tmp = c->spotlights;
	render_plane_norme(c, render, xs);
	color = lighting(&c->l, (t_light *)tmp->content, c);
	tmp = tmp->next;
	while (tmp)
	{
		color = tuple_add(color, lighting(&c->l, (t_light *)tmp->content, c));
		tmp = tmp->next;
	}
	if (((t_plane *)xs->object->obj)->checked == true)
	{
		xs->object->pattern = pattern_plane_checkerboard(&(render->x_point),
				&(c->l.normal_vec));
		intensity = define_intensity(xs->object->pattern);
	}
	color = tuple_multiply(color, intensity);
	return (color_to_int(color));
}
