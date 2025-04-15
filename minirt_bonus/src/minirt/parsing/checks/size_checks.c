/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:14:32 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/13 15:09:04 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	radius_check(t_sphere *s)
{
	return (s->radius <= 0);
}

bool	cylinder_checks(t_cylinder *cylinder)
{
	if (cylinder->height <= 0 || cylinder->diameter <= 0)
		return (true);
	return (false);
}

bool	size_checks(t_config *config)
{
	t_list	*tmp;

	tmp = config->objects_list;
	while (tmp)
	{
		if (((t_object_node *)tmp->content)->type == SPHERE
			&& radius_check((t_sphere *)((t_object_node *)tmp->content)->obj))
			return (true);
		if (((t_object_node *)tmp->content)->type == CYLINDER
			&& cylinder_checks((t_cylinder *)(
				(t_object_node *)tmp->content)->obj))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
