/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:35:51 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/13 14:56:24 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	check_invalid_color(t_color c)
{
	return ((c.x < 0.0 || c.x > 1.0)
		|| (c.y < 0.0 || c.y > 1.0)
		|| (c.z < 0.0 || c.z > 1.0));
}

bool	check_spotlights(t_list *spotlights)
{
	t_list	*tmp;

	if (!spotlights)
		return (false);
	tmp = spotlights;
	while (tmp)
	{
		if (check_invalid_color(((t_light *)tmp->content)->color))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	check_colors_error(t_config *config)
{
	t_list			*tmp;
	t_object_node	*tmpobj;

	if (check_invalid_color(config->ambient_light->color)
		|| check_invalid_color(config->light->color))
		return (true);
	tmp = config->objects_list;
	while (tmp)
	{
		tmpobj = ((t_object_node *)tmp->content);
		if (tmpobj->type == SPHERE)
			if (check_invalid_color(((t_sphere *)tmpobj->obj)->color))
				return (true);
		if (tmpobj->type == CYLINDER)
			if (check_invalid_color(((t_cylinder *)tmpobj->obj)->color))
				return (true);
		if (tmpobj->type == PLANE)
			if (check_invalid_color(((t_plane *)tmpobj->obj)->color))
				return (true);
		if (tmpobj->type == DISK)
			if (check_invalid_color(((t_disk *)tmpobj->obj)->color))
				return (true);
		tmp = tmp->next;
	}
	return (false);
}
