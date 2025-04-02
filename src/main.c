/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:19:18 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	clean_exit(t_config *config)
{
	if (config)
	{
		if (config->mlx && config->img.img)
			mlx_destroy_image(config->mlx, config->img.img);
		if (config->mlx && config->mlx_win)
			mlx_destroy_window(config->mlx, config->mlx_win);
		if (config->mlx)
		{
			mlx_destroy_display(config->mlx);
			free(config->mlx);
		}
		free(config->ambient_light);
		free(config->light);
		free(config->camera);
		free(config);
	}
	exit(0);
}

void	ft_help(char *message)
{
	printf("Error\n");
	if (message)
		printf("%s\n", message);
}

int main(int ac, char **av)
{
	t_config	*c = ft_calloc(sizeof(t_config), 1);
	if (!c)
		return (EXIT_FAILURE);

	if (ac != 2)
		return (ft_help("Invalid number of arguments."), EXIT_FAILURE);
	// test_circle(c);
	parse_scene(c, av[1]);

	clean_exit(c);
	return (EXIT_SUCCESS);
	(void)av;
}

