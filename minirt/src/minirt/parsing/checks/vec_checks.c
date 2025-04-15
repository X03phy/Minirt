/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:37:54 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/13 14:58:06 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	null_vec(t_tuple v)
{
	return (v.x == 0 && v.y == 0 && v.z == 0);
}

bool	invalid_vec(t_tuple v)
{
	if (null_vec(v))
		return (true);
	return ((v.x < 0 || v.x > 1)
		|| (v.y < 0 || v.y > 1) || (v.z < 0 || v.z > 1));
}

bool	check_vectors(t_config *c)
{
	t_list	*tmp;

	if (invalid_vec(c->camera->orientation_vec))
		return (true);
	tmp = c->objects_list;
	while (tmp)
	{
		if (((t_object_node *)tmp->content)->type == CYLINDER)
			if (invalid_vec(((t_cylinder *)(
						(t_object_node *)tmp->content)->obj)->orientation_vec))
				return (true);
		if (((t_object_node *)tmp->content)->type == PLANE)
			if (invalid_vec(((t_plane *)(
						(t_object_node *)tmp->content)->obj)->orientation_vec))
				return (true);
		if (((t_object_node *)tmp->content)->type == DISK)
			if (invalid_vec(((t_disk *)(
						(t_object_node *)tmp->content)->obj)->orientation_vec))
				return (true);
		tmp = tmp->next;
	}
	return (false);
}
