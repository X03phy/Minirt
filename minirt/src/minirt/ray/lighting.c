/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/20 16:08:31 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_color	lighting(t_lighting *l, t_config *c, bool in_shadow)
{
	t_tuple	reflectv;
	double	reflect_dot_eye;

	l->lightv = vector_normalize(tuple_substitute(l->l.position, l->p));
	l->light_real_color = tuple_multiply(l->l.color, l->l.brightness);
	l->ambient = tuple_mult_tuple(l->m.color,
			tuple_multiply(c->ambient_light->color, c->ambient_light->ratio));
	l->ambient = tuple_multiply(l->ambient, l->m.ambient);
	l->light_dot_normal = vector_dot(l->lightv, l->normal_vec);
	l->diffuse = point_create(0, 0, 0);
	l->specular = point_create(0, 0, 0);
	if (l->light_dot_normal >= 0)
	{
		l->diffuse = tuple_mult_tuple(l->m.color, l->light_real_color);
		l->diffuse = tuple_multiply(l->diffuse,
				l->m.diffuse * l->light_dot_normal);
		reflectv = vector_reflect(tuple_negate(l->lightv), l->normal_vec);
		reflect_dot_eye = vector_dot(reflectv, l->eyev);
		if (reflect_dot_eye > 0)
			l->specular = tuple_multiply(l->light_real_color, l->m.specular
					* pow(reflect_dot_eye, l->m.shininess));
	}
	if (in_shadow)
		return (l->ambient);
	return (tuple_add(tuple_add(l->ambient, l->diffuse), l->specular));
}
