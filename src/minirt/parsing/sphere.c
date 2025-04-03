/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:17:48 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/03 11:28:47 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

bool	parse_sphere(t_config *c, char **infos)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 8)
		return (false);
	node = ft_calloc(sizeof(t_object_node), 1);
	if (!node)
		return (false);
	node->type = SPHERE;
	node->obj = ft_calloc(sizeof(t_sphere), 1);
	if (!node->obj)
		return (free(node), false);
	((t_sphere *)node->obj)->center = point_create(ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_sphere *)node->obj)->radius = ft_atod(infos[4]);
	((t_sphere *)node->obj)->color = (0 << 24 | ft_atoi(infos[5]) << 16 | ft_atoi(infos[6]) << 8 | ft_atoi(infos[7]));
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}
