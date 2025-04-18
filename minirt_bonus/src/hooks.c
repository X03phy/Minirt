/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:40:12 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/18 22:15:09 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../libs/minilibx-linux/mlx.h"

int	cross(t_config *config)
{
	clean_exit(config);
	return (0);
}

int	keys(int keycode, t_config *config)
{
	if (keycode == ESCKEY)
		clean_exit(config);
	else if (keycode == P)
		print_config(config);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_config *config)
{
	if (button == 1)
		gen_ray(config, x, y, true);
	else if (button == 2)
		gen_ray(config, x, y, false);
	return (0);
	(void)config;
}

void	install_hooks(t_config *config)
{
	mlx_hook(config->mlx_win, DESTROY_WINDOW, 0L, &cross, config);
	mlx_hook(config->mlx_win, EVENT_KEYPRESS, (1L << 0), keys, config);
	mlx_hook(config->mlx_win, 4, (1L << 2), &mouse_hook, config);
}
