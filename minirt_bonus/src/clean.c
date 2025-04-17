/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:10:10 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/17 16:31:54 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	clean_sphere(t_config *c, t_list **lst)
{
	free(((t_sphere *)((t_object_node *)(*lst)->content)->obj)->texture_name);
	mlx_destroy_image(c->mlx,
		((t_sphere *)((t_object_node *)(*lst)->content)->obj)->texture.img);
	if (((t_sphere *)((t_object_node *)(*lst)->content)->obj)->bumped)
	{
		free(((t_sphere *)((t_object_node *)
					(*lst)->content)->obj)->bump_name);
		mlx_destroy_image(c->mlx,
			((t_sphere *)((t_object_node *)(*lst)->content)->obj)->bump.img);
	}
}

void	clean_plane(t_config *c, t_list **lst)
{
	free(((t_plane *)((t_object_node *)(*lst)->content)->obj)->texture_name);
	mlx_destroy_image(c->mlx,
		((t_plane *)((t_object_node *)(*lst)->content)->obj)->texture.img);
	if (((t_plane *)((t_object_node *)(*lst)->content)->obj)->bumped)
	{
		free(((t_plane *)((t_object_node *)
					(*lst)->content)->obj)->bump_name);
		mlx_destroy_image(c->mlx,
			((t_plane *)((t_object_node *)(*lst)->content)->obj)->bump.img);
	}
}

void	clean_spotlights(t_list **spotlight)
{
	t_list	*tmp;

	while (*spotlight)
	{
		tmp = (*spotlight)->next;
		free((*spotlight)->content);
		free(*spotlight);
		*spotlight = tmp;
	}
	*spotlight = NULL;
}

void	clean_obj_list(t_config *c, t_list **lst, t_list **spotlight)
{
	t_list	*tmp;

	if (!lst || !spotlight)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (((t_object_node *)(*lst)->content)->type == SPHERE &&
			((t_sphere *)((t_object_node *)(*lst)->content)->obj)->textured)
			clean_sphere(c, lst);
		if (((t_object_node *)(*lst)->content)->type == PLANE &&
			((t_plane *)((t_object_node *)(*lst)->content)->obj)->textured)
			clean_plane(c, lst);
		free(((t_object_node *)(*lst)->content)->obj);
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	clean_spotlights(spotlight);
}

int	clean_exit(t_config *config)
{
	clean_obj_list(config, &config->objects_list, &config->spotlights);
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
		free(config->camera);
		free(config->funcs);
		free(config);
	}
	exit(0);
	return (0);
}
