/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_spheres.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:06:55 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 16:14:29 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/objects.h"
#include "../../../include/ray.h"
#include "../../../libs/minilibx-linux/mlx.h"

void	test_phong(t_config *c)
{
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return ;
	c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");
		
	c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);

	t_tuple	ray_origin = point_create(0, 0, -5);
	int	wall_z = 10;
	double	wall_size = 10.0; // change this to change the image dimension

	double	image_pixels = 1000;
	double	pixel_size = wall_size / image_pixels;
	double	half = wall_size / 2;

	t_intersection *xs;
	for (int y = 0; y < image_pixels; y++)
	{
		double world_y = half - (y * pixel_size);
		for (int x = 0; x < image_pixels; x++)
		{
			double world_x = -half + (x * pixel_size);
			t_tuple	position = point_create(world_x, world_y, wall_z);
			t_ray	r = ray_create(ray_origin, vector_normalize(tuple_substitute(position, ray_origin)));
			xs = hit(c, r);
			if (xs && xs->t)
			{
				t_tuple	x_point = ray_position(r, xs->t);
				// test shadow
				bool	in_shadow = is_in_shadow(c, x_point);
				if (xs->object->type == SPHERE)
				{
					t_tuple normal_vec = vector_normalize(tuple_substitute(x_point, ((t_sphere *)xs->object)->center));
					// eye vector
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_sphere *)xs->object)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
					int	colorint = color_to_int(color);
					// printf("Color : 0x%X\n", colorint);
					my_mlx_pixel_put(&c->img, x, y, colorint);

				}
				else if (xs->object->type == PLANE)
				{
					// printf("plane\n");
					t_tuple normal_vec = ((t_plane *)xs->object)->orientation_vec;
					// eye vector
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_plane *)xs->object)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
					int	colorint = color_to_int(color);
					// printf("Color : 0x%X\n", colorint);
					my_mlx_pixel_put(&c->img, x, y, colorint);
				}
				else
				{
					t_tuple normal_vec = vector_normalize(tuple_create(x_point.x - ((t_cylinder *)xs->object)->center.x, 0, x_point.z - ((t_cylinder *)xs->object)->center.z, 0));
					// eye vector
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_cylinder *)xs->object)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
					int	colorint = color_to_int(color);
					// printf("Color : 0x%X\n", colorint);
					my_mlx_pixel_put(&c->img, x, y, colorint);
				}
				free(xs);
			}
		}
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	install_hooks(c);
	mlx_loop(c->mlx);
}
