/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:21:13 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/13 17:25:00 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"
#include <memory.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include "../../../../include/ray.h"
#include "../../../../libs/minilibx-linux/mlx.h"
#include <math.h>

// t_config	*dup_config(t_config *c)
// {
//
// }

bool	clean_threads(t_config *c, t_multi **multi)
{
	pthread_mutex_destroy(&c->config_mut);
	free(*multi);
	return (false);
	(void)c;
	(void)multi;
}

static bool	init_render2(t_config *c, t_render *render)
{	
	render->forward = vector_normalize(c->camera->orientation_vec);
	if (fabs(render->forward.x) < 0.00001 && fabs(render->forward.z) < 0.00001)
		render->up = vector_create(0, 0, 1);
	else
		render->up = vector_create(0, 1, 0);
	render->right = vector_normalize(vector_cross_product(render->forward,
				render->up));
	render->right = tuple_multiply(render->right, -1);
	render->up = vector_normalize(vector_cross_product(render->right,
				render->forward));
	render->up = tuple_multiply(render->up, -1);
	render->wall_z = 10;
	render->dist_cam_wall = render->wall_z - c->camera->position.z;
	render->fov_rad = c->camera->fov * (M_PI / 180.0);
	render->half_view = tan(render->fov_rad / 2) * render->dist_cam_wall;
	render->wall_size = 2 * render->half_view;
	render->image_pixels = WINW;
	render->pixel_size = render->wall_size / render->image_pixels;
	render->half = render->wall_size / 2;
	return (true);
}

static void	hit_that2(t_config *c, t_render *render, int x, int y, t_multi *thdata)
{
	t_intersection	*xs;
	int				color;
	t_config		configdup;

	ft_memcpy(&configdup, c, sizeof(t_config));
	color = 0;
	xs = hit(&configdup, render->ray, thdata);
	if (xs)
	{
		render->x_point = ray_position(render->ray, xs->t);
		if (xs->object->type == SPHERE)
			color = render_sphere(&configdup, xs, render);
		else if (xs->object->type == PLANE)
			color = render_plane(&configdup, xs, render);
		else if (xs->object->type == CYLINDER)
			color = render_cylinder(&configdup, xs, render);
		else if (xs->object->type == DISK)
			color = render_disk(&configdup, xs, render);
		else if (xs->object->type == CONE)
			color = render_cone(&configdup, xs, render);
		pthread_mutex_lock(thdata->config_mut);
		my_mlx_pixel_put(&c->img, x, y, color);
		pthread_mutex_unlock(thdata->config_mut);
		free(xs);
	}
}

static void	*render_loop2(void *thread_data)
{
	t_multi	*thdata;
	int		x;
	int		y;

	thdata = (t_multi *)thread_data;
	y = thdata->minpx - 1;
	while (++y <= thdata->maxpx)
	{
		x = -1;
		thdata->render.world_y = thdata->render.half - (y * thdata->render.pixel_size);
		while (++x < WINW)
		{
			thdata->render.world_x = -thdata->render.half + (x * thdata->render.pixel_size);
			thdata->render.pixel_offset = tuple_add(
					tuple_add(
						tuple_multiply(thdata->render.right, thdata->render.world_x),
						tuple_multiply(thdata->render.up, thdata->render.world_y)
						),
					tuple_multiply(thdata->render.forward, thdata->render.dist_cam_wall));
			thdata->render.pixel_world = tuple_add(thdata->config->camera->position,
					thdata->render.pixel_offset);
			thdata->render.dir = vector_normalize(tuple_substitute(
						thdata->render.pixel_world, thdata->config->camera->position));
			thdata->render.ray = ray_create(thdata->config->camera->position, thdata->render.dir);
			hit_that2(thdata->config, &thdata->render, x, y, thdata);
		}
	}
	return (NULL);
}

bool	render_multi(t_config *c)
{
	int				numofcpus;
	t_multi			*thread_data;
	unsigned long			tids[100];

	ft_bzero(tids, 100);
	numofcpus = sysconf(_SC_NPROCESSORS_ONLN);
	// numofcpus = 1;
	thread_data = ft_calloc(sizeof(t_multi), numofcpus);
	if (!thread_data)
		return (false);
	c->thdatas = thread_data;
	if (pthread_mutex_init(&c->config_mut, NULL))
			return (false);
	for (int i = 0; i < numofcpus; i++) {
		thread_data[i].idx = i + 1;
		thread_data[i].config = c;
		thread_data[i].minpx = (WINH / numofcpus) * i;
		init_render2(c, &thread_data[i].render);
		if (WINH % numofcpus && i + 1 == numofcpus)
			thread_data[i].maxpx = (WINH / numofcpus) * i + (WINH / numofcpus) + (WINH % numofcpus);
		else
			thread_data[i].maxpx = (WINH / numofcpus) * i + (WINH / numofcpus);
		thread_data[i].config_mut = &c->config_mut;
	}

	for (int j = 0; j < numofcpus; j++) {
		printf("thread num %d will render pixel from %d to %d\n", thread_data[j].idx, thread_data[j].minpx, thread_data[j].maxpx);
	}
	
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return (false);
	c->mlx_win = mlx_new_window(c->mlx, WINW, WINH, "MiniRT");
	c->img.img = mlx_new_image(c->mlx, WINW, WINH);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);

	for (int k = 0; k < numofcpus; k++) {
		pthread_create(&tids[k], NULL, render_loop2, (void *)&thread_data[k]);
	}

	for (int m = 0; m < numofcpus; m++) {
		pthread_join(tids[m], NULL);
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	install_hooks(c);
	mlx_loop(c->mlx);

	clean_threads(c, &thread_data);
	return (true);
}
