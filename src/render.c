/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:45:53 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/09 14:59:02 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../include/ray.h"
#include "../libs/minilibx-linux/mlx.h"

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
	int	wall_z = 10;
	double	wall_size = 10.0; // fov ?

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
			// printf("pixel : x = %d, y = %d\n", x, y);
			if (xs)
			{
				t_tuple	x_point = ray_position(r, xs->t);
				bool	in_shadow = is_in_shadow(c, x_point, get_obj_id(xs->object));
				// bool	in_shadow = is_in_shadow(c, x_point, 1);
				if (xs->object->type == SPHERE)
				{
					t_tuple normal_vec = vector_normalize(tuple_substitute(x_point, ((t_sphere *)xs->object->obj)->center));
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_sphere *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
					int	colorint = color_to_int(color);
					my_mlx_pixel_put(&c->img, x, y, colorint);
				}
				else if (xs->object->type == PLANE)
				{
					t_tuple normal_vec = ((t_plane *)xs->object->obj)->orientation_vec;
					// eye vector
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_plane *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
					int	colorint = color_to_int(color);
					my_mlx_pixel_put(&c->img, x, y, colorint);
				}
				else if (xs->object->type == CYLINDER)
				{
					t_cylinder *cylinder;
					cylinder = ((t_cylinder *)xs->object->obj);
					t_tuple oc = tuple_substitute(x_point, cylinder->center);
					double m = vector_dot(oc, cylinder->orientation_vec);
					t_tuple proj = tuple_multiply(cylinder->orientation_vec, m);
					t_tuple normal_vec = vector_normalize(tuple_substitute(oc, proj));
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_cylinder *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, in_shadow);
					int	colorint = color_to_int(color);
					my_mlx_pixel_put(&c->img, x, y, colorint);
				}
				else if (xs->object->type == DISK)
				{
					t_tuple normal_vec = ((t_disk *)xs->object->obj)->orientation_vec;
					t_tuple	eyev = tuple_negate(r.direction);
					t_tuple color = lighting(((t_disk *)xs->object->obj)->material, *c->light, x_point, eyev, normal_vec, c, false);
					int	colorint = color_to_int(color);
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
