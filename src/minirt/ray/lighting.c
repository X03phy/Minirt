/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/09 11:26:38 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

// vieu
t_color lighting2(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv, t_config *c, bool in_shadow)
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
	if (in_shadow)
		return (ambient);
	return (tuple_add(tuple_add(ambient, diffuse), specular));
	(void)c;
	(void)in_shadow;
}

t_color lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv, t_config *c, bool in_shadow)
{
    t_tuple lightv = vector_normalize(tuple_substitute(l.position, p));

	t_color	light_real_color = tuple_multiply(l.color, l.brightness);

    t_color ambient = tuple_add(m.color, tuple_multiply(c->ambient_light->color, c->ambient_light->ratio));
    ambient = tuple_multiply(ambient, m.ambient);

    double light_dot_normal = vector_dot(lightv, normalv);

    t_color diffuse = point_create(0, 0, 0);
    t_color specular = point_create(0, 0, 0);
    if (light_dot_normal >= 0)
    {
        t_color diffuse_color = tuple_add(m.color, light_real_color);
        diffuse = tuple_multiply(diffuse_color, m.diffuse * light_dot_normal);

        t_tuple reflectv = vector_reflect(tuple_negate(lightv), normalv);
        double reflect_dot_eye = vector_dot(reflectv, eyev);
        if (reflect_dot_eye > 0)
        {
            double factor = pow(reflect_dot_eye, m.shininess);
            specular = tuple_multiply(light_real_color, m.specular * factor);
        }
    }
	if (in_shadow)
		return (ambient);
    return tuple_add(tuple_add(ambient, diffuse), specular);
}
