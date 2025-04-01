/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 10:54:35 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
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
	
	double	v1[] = {1, 2, 6, -5, 8, -4, 2, 6, 4};
	double	v2[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9};
	// double	v1[] = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};
	double	values[] = {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6};
	double	values2[] = {-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0};

	printf("Determinant/cofactor = \n");
	printf("test 1 : \n");
	t_matrice	*m1 = new_matrice(3, 3, v1);
	print_matrice(m1);

	printf("cofactor (A, 0, 0): %f\n", cofactor_matrice(m1, 0, 0));
	printf("cofactor (A, 0, 1): %f\n", cofactor_matrice(m1, 0, 1));
	printf("cofactor (A, 0, 2): %f\n", cofactor_matrice(m1, 0, 2));
	printf("Determinant A: %f\n", matrice_determinant(m1));


	printf("\ntest 2 : \n");
	t_matrice	*m2 = new_matrice(4, 4, v2);
	print_matrice(m2);

	printf("cofactor (A, 0, 0): %f\n", cofactor_matrice(m2, 0, 0));
	printf("cofactor (A, 0, 1): %f\n", cofactor_matrice(m2, 0, 1));
	printf("cofactor (A, 0, 2): %f\n", cofactor_matrice(m2, 0, 2));
	printf("cofactor (A, 0, 3): %f\n", cofactor_matrice(m2, 0, 3));
	printf("Determinant A: %f\n", matrice_determinant(m2));



	clean_matrice(&m1);
	clean_matrice(&m2);


	printf("\n\nMatrices inversion = \n");
	printf("test1 :\n");
	t_matrice *m3 = new_matrice(4, 4, values);
	t_matrice *m4 = new_matrice(4, 4, values2);

	print_matrice(m3);
	print_matrice(m4);

	clean_matrice(&m3);
	clean_matrice(&m4);
	//
	// t_matrice	*m3inv = inversion(t_matrice *m)
	// c->mlx = mlx_init();
	// if (c->mlx == NULL)
	// 	return (clean_exit(c), EXIT_FAILURE);
	// c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");
	//
	// t_tuple	p = new_tuple(0, 1, 0, POINT);
	// t_tuple	vel = mul_tuple(normalize_tuple(new_tuple(1, 1.8, 0, VEC)), 11.25);
	// t_tuple gravity = new_tuple(0, -0.1, 0, VEC);
	// t_tuple vent = new_tuple(-0.01, 0, 0, VEC);
	//
	// c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	// c->img.addr = mlx_get_data_addr(c->img.img,
	// 		&c->img.bits_per_pixels,
	// 		&c->img.line_len, &c->img.endian);
	// while (p.x >= 0 && p.y >= 0)
	// {
	// 	int x = (int)p.x;
	// 	int y = 1000 - (int)p.y;
	// 	printf("Point : x = %d, y = %d\n", x, y);
	// 	my_mlx_pixel_put(&c->img, x, y, 0x00FFFF00);
	// 	p = add_tuples(p, vel);
	// 	vel = add_tuples(vel, add_tuples(gravity, vent));
	// }
	// mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	// install_hooks(c);
	// mlx_loop(c->mlx);

	clean_exit(c);
	return (0 * ac * (long)av);
}

