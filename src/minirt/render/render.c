/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:45:53 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/10 09:45:16 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include "../../../libs/minilibx-linux/mlx.h"
#include <math.h>

void	render(t_config *c)
{
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return ;
	c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");
	c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);

	t_tuple	ray_origin = point_create(c->camera->position.x, c->camera->position.y, c->camera->position.z);
	int		wall_z = 10;
	double	dist_cam_wall = wall_z - c->camera->position.z;
	double	fov_rad = c->camera->fov * (M_PI / 180.0);
	double	half_view = tan(fov_rad / 2) * dist_cam_wall;

	double	wall_size = 2 * half_view;

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
			// t_tuple	direction = vector_normalize(tuple_substitute(position, ray_origin));
			// t_ray	r = ray_create(ray_origin, direction);
			xs = hit(c, r);
			if (xs)
			{
				t_tuple	x_point = ray_position(r, xs->t);
				bool	in_shadow = is_in_shadow(c, x_point, get_obj_id(xs->object));
				if (xs->object->type == SPHERE)
					my_mlx_pixel_put(&c->img, x, y, render_sphere(c, x_point, xs, r, in_shadow));
				else if (xs->object->type == PLANE)
					my_mlx_pixel_put(&c->img, x, y, render_plane(c, x_point, xs, r, in_shadow));
				else if (xs->object->type == CYLINDER)
					my_mlx_pixel_put(&c->img, x, y, render_cylinder(c, x_point, xs, r, in_shadow));
				else if (xs->object->type == DISK)
					my_mlx_pixel_put(&c->img, x, y, render_disk(c, x_point, xs, r, in_shadow));
				free(xs);
			}
		}
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	install_hooks(c);
	mlx_loop(c->mlx);
}
