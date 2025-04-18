/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:17:48 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/10 10:33:24 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

static void	fill_sphere(t_config *c, char **infos, t_object_node *node)
{
	((t_sphere *)node->obj)->id = ++(c->total_objects);
	((t_sphere *)node->obj)->center = point_create(
			ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_sphere *)node->obj)->radius = ft_atod(infos[4]);
	((t_sphere *)node->obj)->color = point_create(
			ft_atoi(infos[5]) / 255.0,
			ft_atoi(infos[6]) / 255.0, ft_atoi(infos[7]) / 255.0);
	((t_sphere *)node->obj)->material = default_material(
			((t_sphere *)node->obj)->color);
}

bool	parse_sphere(t_config *c, char **infos, int currline)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 8)
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
	node->type = SPHERE;
	node->obj = ft_calloc(sizeof(t_sphere), 1);
	if (!node->obj)
		return (free(node), false);
	fill_sphere(c, infos, node);
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}
