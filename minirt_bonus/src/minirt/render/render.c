/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:45:53 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/20 15:37:13 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include "../../../libs/minilibx-linux/mlx.h"
#include <math.h>

bool	init_render(t_config *c, t_render *render)
{
	c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");
	c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);
	render->wall_z = 10;
	render->dist_cam_wall = render->wall_z - c->camera->position.z;
	render->fov_rad = c->camera->fov * (M_PI / 180.0);
	render->half_view = tan(render->fov_rad / 2) * render->dist_cam_wall;
	render->wall_size = 2 * render->half_view;
	render->image_pixels = 1000;
	render->pixel_size = render->wall_size / render->image_pixels;
	render->half = render->wall_size / 2;
	return (true);
}

void	hit_that(t_config *c, t_render *render, int x, int y)
{
	t_intersection	*xs;

	xs = hit(c, render->ray, NULL);
	if (xs)
	{
		render->x_point = ray_position(render->ray, xs->t);
		if (xs->object->type == SPHERE)
			my_mlx_pixel_put(&c->img, x, y,
				render_sphere(c, xs, render));
		else if (xs->object->type == PLANE)
			my_mlx_pixel_put(&c->img, x, y,
				render_plane(c, xs, render));
		else if (xs->object->type == CYLINDER)
			my_mlx_pixel_put(&c->img, x, y,
				render_cylinder(c, xs, render));
		else if (xs->object->type == DISK)
			my_mlx_pixel_put(&c->img, x, y,
				render_disk(c, xs, render));
		else if (xs->object->type == CONE)
			my_mlx_pixel_put(&c->img, x, y,
				render_cone(c, xs, render));
		free(xs);
	}
}

void	render_loop(t_config *c, t_render *render)
{
	int		x;
	int		y;

	y = -1;
	while (++y < render->image_pixels)
	{
		x = -1;
		render->world_y = render->half - (y * render->pixel_size);
		while (++x < render->image_pixels)
		{
			render->world_x = -render->half + (x * render->pixel_size);
			render->pixel_offset = tuple_add(
					tuple_add(
						tuple_multiply(render->right, render->world_x),
						tuple_multiply(render->up, render->world_y)
						),
					tuple_multiply(render->forward, render->dist_cam_wall));
			render->pixel_world = tuple_add(c->camera->position,
					render->pixel_offset);
			render->dir = vector_normalize(tuple_substitute(
						render->pixel_world, c->camera->position));
			render->ray = ray_create(c->camera->position, render->dir);
			hit_that(c, render, x, y);
		}
	}
}

void	render(t_config *c)
{	
	if (c->img.img)
		mlx_destroy_image(c->mlx, c->img.img);
	if (c->mlx_win == NULL)
		c->mlx_win = mlx_new_window(c->mlx, WINW, WINH, "MiniRT");
	c->img.img = mlx_new_image(c->mlx, WINW, WINH);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);
	if (init_render(c, &c->render) == false)
		return ;
	c->render.forward = vector_normalize(c->camera->orientation_vec);
	if (fabs(c->render.forward.x) < 0.00001
		&& fabs(c->render.forward.z) < 0.00001)
		c->render.up = vector_create(0, 0, 1);
	else
		c->render.up = vector_create(0, 1, 0);
	c->render.right = vector_normalize(vector_cross_product(c->render.forward,
				c->render.up));
	c->render.right = tuple_multiply(c->render.right, -1);
	c->render.up = vector_normalize(vector_cross_product(c->render.right,
				c->render.forward));
	c->render.up = tuple_multiply(c->render.up, -1);
	render_loop(c, &c->render);
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
}
