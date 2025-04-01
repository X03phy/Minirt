/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:22:29 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
#include <stdlib.h>

void	clean_exit(t_config *config)
{
	if (config)
	{
		if (config->mlx && config->img.img)
			mlx_destroy_image(config->mlx, config->img.img);
		if (config->mlx && config->mlx_win)
			mlx_destroy_window(config->mlx, config->mlx_win);
		if (config->mlx)
		{
			mlx_destroy_display(config->mlx);
			free(config->mlx);
		}
		free(config);
	}
	exit(0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixels / 8));
	*(unsigned int *)dst = color;
}

int main(int ac, char **av)
{
	t_config	*c = ft_calloc(sizeof(t_config), 1);
	if (!c)
		return (EXIT_FAILURE);
	
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return (clean_exit(c), EXIT_FAILURE);
	c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");

	t_tuple	p = new_tuple(1, 0, 0, POINT);
	t_matrice	*transform = rotate_z(M_PI / 6);
	t_matrice	*scale = scaling_matrix(100, 100, 0);
	t_tuple		tmp;
	int	i = 0;
	c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);
	while (i < 12)
	{
		p = mul_matrix_tuple(transform, p);
		tmp = mul_matrix_tuple(scale, p);
		my_mlx_pixel_put(&c->img, (int)tmp.x + 500, (int)tmp.y + 500, 0x00FFFF00);
		i++;
	}
	clean_matrix(&transform);
	clean_matrix(&scale);
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	install_hooks(c);
	mlx_loop(c->mlx);

	clean_exit(c);
	return (0 * ac * (long)av);
}
