/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 17:52:32 by ebonutto         ###   ########.fr       */
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
		ft_lstclear(&config->objects_list, free);
		free(config->ambient_light);
		free(config->light);
		free(config->camera);
		free(config->funcs);
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
	(void)av;
	(void)ac;

	t_tuple	v = new_vec(1, -1, 0);
	t_tuple	n = new_vec(0, 1, 0);
	t_tuple r = reflect(v, n);
	
	
	print_tuple(&r);
	// t_config	*c = init_config();
	// if (!c)
	// 	return (EXIT_FAILURE);
	// if (ac != 2)
	// 	return (ft_help("Invalid number of arguments."), EXIT_FAILURE);
	// test_circle(c);
	// test_eclairage(c);
	// parse_scene(c, av[1]);

	// clean_exit(c);
	// return (EXIT_SUCCESS);
}

