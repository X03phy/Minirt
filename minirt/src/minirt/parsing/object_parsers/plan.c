/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:02 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 09:35:02 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

static void	fill_plan(t_config *c, char **infos, t_object_node *node)
{
	((t_plane *)node->obj)->id = ++(c->total_objects);
	((t_plane *)node->obj)->center = point_create(
			ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_plane *)node->obj)->orientation_vec = vector_normalize(vector_create(
				ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6])));
	((t_plane *)node->obj)->color = point_create(
			ft_atoi(infos[7]) / 255.0,
			ft_atoi(infos[8]) / 255.0, ft_atoi(infos[9]) / 255.0);
	((t_plane *)node->obj)->material = default_material(
			((t_plane *)node->obj)->color);
	((t_plane *)node->obj)->material.specular = 0.1;
	((t_plane *)node->obj)->material.shininess = 10.0;
}

bool	parse_plan(t_config *c, char **infos, int currline)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 10)
		return (false);
	if (!check_only_valid_float(&infos[1]))
	{
		c->err.msg = INVALID_NUMBER;
		c->err.line = currline;
		return (false);
	}
	node = ft_calloc(sizeof(t_object_node), 1);
	if (!node)
		return (false);
	node->type = PLANE;
	node->obj = ft_calloc(sizeof(t_plane), 1);
	if (!node->obj)
		return (free(node), false);
	fill_plan(c, infos, node);
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}
