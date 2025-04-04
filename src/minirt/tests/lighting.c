/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:49:22 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/04 12:28:38 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

int	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_tuple	effective_color = tuple_multiply(material.color, light.brightness); // ntensite de la couleurr de la boule (du a la lumiere)
	t_tuple lightv = vector_normalize(tuple_substitute(light.position, point)); // direction de la lumiere normalisee
	t_tuple ambiant = tuple_multiply(effective_color, );
	int ambient = effective_color * 1; // (1 = ambient)
	int	diffuse, specular;
	double	light_dot_normal = vector_dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = 0x000000;
		specular = 0x000000;
	}
	else
	{
		diffuse = effective_color * 1 * light_dot_normal; // (material.diffuse)
		t_tuple tuple_multiplyv = vector_tuple_multiply(tuple_multiply(lightv, -1), normalv);
		double	tuple_multiply_dot_eye = vector_dot(tuple_multiplyv, eyev);
		if (tuple_multiply_dot_eye <= 0)
			specular = 0x000000;
		else
		{
			double	factor = pow(tuple_multiply_dot_eye, 0.5);
			specular = 1 * 0.5 * factor;
		}
	}
	return (ambient + diffuse + specular);
}

void	test_light(t_config *c)
{
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return ;
	c->mlx_win = mlx_new_window(c->mlx, 500, 500, "MiniRT");
		
	c->img.img = mlx_new_image(c->mlx, 500, 500);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);

	
}
