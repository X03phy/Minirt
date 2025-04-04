/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:07:38 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/04 15:20:25 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (fmin(fmax(color.x, 0.0), 1.0) * 255);
	g = (fmin(fmax(color.y, 0.0), 1.0) * 255);
	b = (fmin(fmax(color.z, 0.0), 1.0) * 255);
	return (
		(r << 16 | g << 8 | b)
	);
}

t_material	default_material(t_color color)
{
	t_material m;
	m.ambient = 0.1;
    m.diffuse = 0.9;
    m.specular = 0.9;
    m.shininess = 200.0;
    m.color = color;
	return (m);
}
