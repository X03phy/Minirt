/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclairage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:01:46 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/04 17:03:16 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/objects.h"
#include "../../../include/ray.h"
#include "../../../include/wall.h"
#include "../../../libs/minilibx-linux/mlx.h"

void	test_eclairage(t_config *c)
{
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return ;
	c->mlx_win = mlx_new_window(c->mlx, 500, 500, "MiniRT");
		
	c->img.img = mlx_new_image(c->mlx, 500, 500);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);

	t_tuple	ray_origin = point_create(0, 0, -5);
	int	wall_z = 10;
	double	wall_size = 7.0;

	// calcul de la taille d'un pixel de l'image dans la simulation 3D
	double	image_pixels = 500;
	double	pixel_size = wall_size / image_pixels;
	double	half = wall_size / 2;

	t_sphere s;
	s.center = point_create(0, 0, 0);
	s.radius = 1;

	double *xs;
	for (int y = 0; y < image_pixels; y++)
	{
		double world_y = half - (y * pixel_size);
		for (int x = 0; x < image_pixels; x++)
		{
			double world_x = -half + (x * pixel_size);
			t_tuple	position = point_create(world_x, world_y, wall_z);        // position reelle de mon pixel dans le monde 3D
			t_ray	r = ray_create(ray_origin, vector_normalize(tuple_substitute(position, ray_origin)));
			xs = ray_sphere_intersection(s, r);
			if (xs)
			{
				my_mlx_pixel_put(&c->img, x, y, 0x000000FF);
				free(xs);
			}
		}
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	install_hooks(c);
	mlx_loop(c->mlx);
}
