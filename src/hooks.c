/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:40:12 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:28:24 by ebonutto         ###   ########.fr       */
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
	return (0);
}

void	install_hooks(t_config *config)
{
	mlx_hook(config->mlx_win, DESTROY_WINDOW, 0L, &cross, config);
	mlx_hook(config->mlx_win, EVENT_KEYPRESS, (1L << 0), keys, config);
}
