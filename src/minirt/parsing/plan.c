/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:02 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:38 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

bool	parse_plan(t_config *c, char **infos)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 10)
		return (false);
	node = ft_calloc(sizeof(t_object_node), 1);
	if (!node)
		return (false);
	node->type = PLANE;
	node->obj = ft_calloc(sizeof(t_plane), 1);
	if (!node->obj)
		return (free(node), false);
	((t_plane *)node->obj)->center = new_point(ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_plane *)node->obj)->orientation_vec = new_vec(ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6]));
	((t_plane *)node->obj)->color = (0 << 24 | ft_atoi(infos[7]) << 16 | ft_atoi(infos[8]) << 8 | ft_atoi(infos[9]));
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}
