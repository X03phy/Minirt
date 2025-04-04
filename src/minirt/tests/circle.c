/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:11:32 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/03 13:40:06 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../libs/minilibx-linux/mlx.h"

void	test_circle(t_config *c)
{
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return ;
	c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");

	t_tuple	p = tuple_create(1, 0, 0, POINT);
	t_matrix	*transform = matrix_rotate_z(M_PI / 2000);
	t_matrix	*scale = matrix_scale(500, 500, 0);
	t_matrix	*scale2 = matrix_scale(499, 499, 0);	
	t_tuple		tmp;
	int	i = 0;
	c->img.img = mlx_new_image(c->mlx, 1000, 1000);
	c->img.addr = mlx_get_data_addr(c->img.img,
			&c->img.bits_per_pixels,
			&c->img.line_len, &c->img.endian);
	while (i < 4000)
	{
		p = matrix_multiply_tuple(transform, p);
		tmp = matrix_multiply_tuple(scale, p);
		my_mlx_pixel_put(&c->img, (int)tmp.x + 500, (int)tmp.y + 500, 0x00FF00FF);
		for (int j = 499; j > 0; j--) {
			scale2->matrix[0][0] = j;
			scale2->matrix[1][1] = j;
			tmp = matrix_multiply_tuple(scale2, p);
			my_mlx_pixel_put(&c->img, (int)tmp.x + 500, (int)tmp.y + 500, 0x00FF00FF);
		}
		i++;
	}
	matrix_free(&scale2);
	matrix_free(&transform);
	matrix_free(&scale);
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
	install_hooks(c);
	mlx_loop(c->mlx);
}
