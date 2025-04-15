/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/09 14:52:11 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	clean_obj_list(t_list	**lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(((t_object_node *)(*lst)->content)->obj);
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

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
		clean_obj_list(&config->objects_list);
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
	printf(GRN"Usage : ./minirt <scene.rt>\n"RESET);
}

void	print_err(t_config *c, char *msg)
{
	printf(HRED"Error.\n"RESET);
	if (msg)
		return ((void)printf("%s\n", msg));
	if (c->err.line > -1)
		printf("In scene file : %s\n", c->av[1]);
	if (ft_strcmp(INVALID_OBJECT, c->err.msg) == 0
		|| ft_strcmp(INVALID_NUMBER, c->err.msg) == 0)
		printf(c->err.msg, c->err.line);
	else
		printf(c->err.msg, c->av[1]);
}

int	main(int ac, char **av)
{
	t_config	*c;

	c = init_config(ac, av);
	if (!c)
		return (perror("Can't initialize config : "), EXIT_FAILURE);
	if (ac != 2)
		return (ft_help("Invalid number of arguments."),
			clean_exit(c), EXIT_FAILURE);
	if (parse_scene(c, av[1]) == false)
		return (ft_help("Invalid scene."), clean_exit(c), EXIT_FAILURE);
	check_config(c);
	if (c->err.msg)
		return (print_err(c, NULL), clean_exit(c), EXIT_FAILURE);
	if (c)
		print_config(c);
	render(c);
	clean_exit(c);
	return (EXIT_SUCCESS);
}
