/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:10 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <math.h>
#include <stdio.h>
#include "time.h"
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

t_sphere	new_sphere(t_tuple center)
{
	srand(time(NULL));
	t_sphere s;
	s.center = center;
	s.radius = (rand() % (20 - 1 + 1)) + 1;
	return (s);
}

int main(int ac, char **av)
{
	t_config	*c = ft_calloc(sizeof(t_config), 1);
	if (!c)
		return (EXIT_FAILURE);
	
	t_ray	r = create_ray(new_point(0, 1, -5), new_vec(0, 0, 1));
	t_sphere	sphere = new_sphere(new_point(0, 0, 0));

	double	*inter = intersection(sphere, r);
	if (!inter)
		printf("no intersections\n");
	else
	{
		printf("inter[0] = %f, inter[1] = %f\n", inter[0], inter[1]);
		free(inter);
	}
	// c->mlx = mlx_init();
	// if (c->mlx == NULL)
	// 	return (clean_exit(c), EXIT_FAILURE);
	// c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");
	//
	// t_tuple	p = new_tuple(1, 0, 0, POINT);
	// t_matrice	*transform = rotate_z(M_PI / 2000);
	// t_matrice	*scale = scaling(500, 500, 0);
	// t_matrice	*scale2 = scaling(499, 499, 0);	
	// t_tuple		tmp;
	// int	i = 0;
	// c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	// c->img.addr = mlx_get_data_addr(c->img.img,
	// 		&c->img.bits_per_pixels,
	// 		&c->img.line_len, &c->img.endian);
	// while (i < 4000)
	// {
	// 	p = mul_matrice_tuple(transform, p);
	// 	tmp = mul_matrice_tuple(scale, p);
	// 	my_mlx_pixel_put(&c->img, (int)tmp.x + 500, (int)tmp.y + 500, 0x00FF00FF);
	// 	for (int j = 499; j > 0; j--) {
	// 		scale2->matrice[0][0] = j;
	// 		scale2->matrice[1][1] = j;
	// 		tmp = mul_matrice_tuple(scale2, p);
	// 		my_mlx_pixel_put(&c->img, (int)tmp.x + 500, (int)tmp.y + 500, 0x00FF00FF);
	// 	}
	// 	i++;
	// }
	//
	// clean_matrice(&scale2);
	// clean_matrice(&transform);
	// clean_matrice(&scale);
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	// install_hooks(c);
	// mlx_loop(c->mlx);

	clean_exit(c);
	return (0 * ac * (long)av);
}

