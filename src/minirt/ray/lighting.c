/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/04 09:43:28 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_color	lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv)
{
	t_tuple	effective_color = mul_tuple(m.color, l.brightness);
	
	t_tuple	lightv = normalize_tuple(sub_tuples(l.position, p));

	t_tuple ambient = mul_tuple(effective_color, m.ambient);

	double	light_dot_normal = dot_tuples(lightv, normalv);
	
	t_color	diffuse = new_point(0, 0, 0);
	t_color	specular = new_point(0, 0, 0);
	if (light_dot_normal >= 0) 
	{
		diffuse = mul_tuple(effective_color, m.diffuse * light_dot_normal);
		t_tuple	reflectv = reflect(new_neg_tuple(lightv), normalv);
		double reflect_dot_eye = dot_tuples(reflectv, eyev);
		if (reflect_dot_eye > 0)
		{
			double factor = pow(reflect_dot_eye, m.shininess);
			t_color	white = new_point(1, 1, 1);
			specular = mul_tuple(white, m.specular * factor);
		}
	}
	return (add_tuples(add_tuples(ambient, diffuse), specular));
}
