/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/04 12:31:03 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_color	lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv)
{
	t_tuple	effective_color = tuple_multiply(m.color, l.brightness);
	
	t_tuple	lightv = vector_normalize(tuple_substitute(l.position, p));

	t_tuple ambient = tuple_multiply(effective_color, m.ambient);

	double	light_dot_normal = vector_dot(lightv, normalv);
	
	t_color	diffuse = point_create(0, 0, 0);
	t_color	specular = point_create(0, 0, 0);
	if (light_dot_normal >= 0) 
	{
		diffuse = tuple_multiply(effective_color, m.diffuse * light_dot_normal);
		t_tuple	reflectv = vector_reflect(tuple_negate(lightv), normalv);
		double tuple_multiply_dot_eye = vector_dot(reflectv, eyev);
		if (tuple_multiply_dot_eye > 0)
		{
			double factor = pow(tuple_multiply_dot_eye, m.shininess);
			t_color	white = point_create(1, 1, 1);
			specular = tuple_multiply(white, m.specular * factor);
		}
	}
	return (tuple_add(tuple_add(ambient, diffuse), specular));
}
