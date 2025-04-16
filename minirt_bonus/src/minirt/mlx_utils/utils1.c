/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:55 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 13:42:46 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixels / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_color(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixels / 8));
	return (*(unsigned int *)dst);
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
