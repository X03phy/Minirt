/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:33 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/19 17:24:28 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

void	move_cam(t_config *config, int keycode)
{
	t_tuple	forward;
	t_tuple	world_up;
	t_tuple	right;
	t_tuple	delta;

	forward = vector_normalize(config->camera->orientation_vec);
	world_up = tuple_create(0, 1, 0, 0);
	right = vector_normalize(vector_cross_product(forward, world_up));
	delta = tuple_create(0, 0, 0, VEC);
	if (keycode == W)
		delta = tuple_add(delta, forward);
	else if (keycode == S)
		delta = tuple_substitute(delta, forward);
	else if (keycode == D)
		delta = tuple_substitute(delta, right);
	else if (keycode == A)
		delta = tuple_add(delta, right);
	else if (keycode == SPACE)
		delta = tuple_add(delta, world_up);
	else if (keycode == CTRL)
		delta = tuple_substitute(delta, world_up);
	delta = tuple_multiply(delta, MOVEMENT_SPEED);
	config->camera->position = tuple_add(config->camera->position, delta);
	render_multi(config);
}

void	move_cam_vec(t_config *config, int keycode)
{
	t_matrix	*rot;

	rot = NULL;
	if (keycode == UP)
		rot = matrix_rotate_x(-M_PI / ROTATION_SPEED);
	else if (keycode == DOWN)
		rot = matrix_rotate_x(M_PI / ROTATION_SPEED);
	else if (keycode == RIGHT)
		rot = matrix_rotate_y(M_PI / ROTATION_SPEED);
	else if (keycode == LEFT)
		rot = matrix_rotate_y(-M_PI / ROTATION_SPEED);
	if (!rot)
		return ;
	config->camera->orientation_vec = matrix_multiply_tuple(rot,
			config->camera->orientation_vec);
	matrix_free(&rot);
	render_multi(config);
}
