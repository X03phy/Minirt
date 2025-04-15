/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:55 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 11:19:12 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixels / 8));
	*(unsigned int *)dst = color;
}

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
