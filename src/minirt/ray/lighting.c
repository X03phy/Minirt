/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 19:35:13 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

int	lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv)
{
	int	effective_color = m.color * l.brightness;
	
	t_tuple	lightv = normalize_tuple(sub_tuples(l.position, p));

	double ambient = effective_color * m.ambient;

	int	light_dot_normal = dot_tuples(lightv, normalv);
	if (light_dot_normal < 0)
	{
		m.diffuse = 0x00000000;
		m.specular = 0x00000000;
	}
	else 
	{
		m.diffuse = effective_color * m.diffuse * light_dot_normal;
		t_tuple	reflectv = reflect(new_neg_tuple(lightv), normalv);
		double reflect_dot_eye = dot_tuples(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			m.specular = 0x00000000;
		else
		{
			double factor = pow(reflect_dot_eye, m.shininess);
			m.specular = l.brightness * m.specular * factor;
		}
	}
	printf("color : %f\n", ambient);
	printf("color : %f\n", m.diffuse);
	printf("color : %f\n", m.specular);
	return (ambient + m.diffuse + m.specular);
}

