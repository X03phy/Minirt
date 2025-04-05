/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:18:50 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 15:46:55 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_cylinder(t_config *c, char **infos, int currline)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 12)
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
	node->type = CYLINDER;
	node->obj = ft_calloc(sizeof(t_cylinder), 1);
	if (!node->obj)
		return (free(node), false);
	((t_cylinder *)node->obj)->id = ++(c->total_objects);
	((t_cylinder *)node->obj)->center = point_create(ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_cylinder *)node->obj)->orientation_vec = vector_create(ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6]));
	((t_cylinder *)node->obj)->diameter = ft_atod(infos[7]);
	((t_cylinder *)node->obj)->height = ft_atod(infos[8]);
	((t_cylinder *)node->obj)->color = point_create(ft_atoi(infos[9]) / 255.0, ft_atoi(infos[10]) / 255.0, ft_atoi(infos[11]) / 255.0);
	((t_cylinder *)node->obj)->material = default_material(((t_cylinder *)node->obj)->color);
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}
