/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:18:50 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 09:34:34 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_disk(t_config *c, t_cylinder *cy, int hb)
{
	t_object_node	*node;
	t_list			*lsttmp;

	node = ft_calloc(sizeof(t_object_node), 1);
	if (!node)
		return (false);
	node->type = DISK;
	node->obj = ft_calloc(sizeof(t_disk), 1);
	if (!node->obj)
		return (free(node), false);
	((t_disk *)node->obj)->id = ++(c->total_objects);
	((t_disk *)node->obj)->orientation_vec = vector_normalize(tuple_multiply(
			cy->orientation_vec, hb));
	((t_disk *)node->obj)->center = tuple_add(cy->center,
			tuple_multiply(cy->orientation_vec, (cy->height / 2) * hb));
	((t_disk *)node->obj)->radius = cy->diameter / 2;
	((t_disk *)node->obj)->color = cy->color;
	((t_disk *)node->obj)->material = cy->material;
	((t_disk *)node->obj)->material.specular = 0.1;
	((t_disk *)node->obj)->material.shininess = 10.0;
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}

static void	fill_cylinder(t_config *c, char **infos, t_object_node *node)
{
	((t_cylinder *)node->obj)->id = ++(c->total_objects);
	((t_cylinder *)node->obj)->center = point_create(
			ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_cylinder *)node->obj)->orientation_vec = vector_normalize(vector_create(
				ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6])));
	((t_cylinder *)node->obj)->diameter = ft_atod(infos[7]);
	((t_cylinder *)node->obj)->height = ft_atod(infos[8]);
	((t_cylinder *)node->obj)->color = point_create(
			ft_atoi(infos[9]) / 255.0,
			ft_atoi(infos[10]) / 255.0, ft_atoi(infos[11]) / 255.0);
	((t_cylinder *)node->obj)->material = default_material(
			((t_cylinder *)node->obj)->color);
}

static bool	set_error(t_config *c, char *msg, int currline)
{
	c->err.msg = msg;
	c->err.line = currline;
	return (false);
}

bool	parse_cylinder(t_config *c, char **infos, int currline)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 12)
		return (false);
	if (!check_only_valid_float(&infos[1]))
		return (set_error(c, INVALID_NUMBER, currline));
	node = ft_calloc(sizeof(t_object_node), 1);
	if (!node)
		return (false);
	node->type = CYLINDER;
	node->obj = ft_calloc(sizeof(t_cylinder), 1);
	if (!node->obj)
		return (free(node), false);
	fill_cylinder(c, infos, node);
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	parse_disk(c, (t_cylinder *)node->obj, 1);
	parse_disk(c, (t_cylinder *)node->obj, -1);
	return (true);
}
