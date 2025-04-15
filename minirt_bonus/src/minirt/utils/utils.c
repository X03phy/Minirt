/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:07:38 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/15 14:39:08 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_material	default_material(t_color color)
{
	t_material	m;

	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9; // 0.1
	m.shininess = 200.0; // 10.0
	m.color = color;
	return (m);
}

t_sphere	*listptr_to_sphere(t_list *elem)
{
	return ((t_sphere *)((t_object_node *)elem->content)->obj);
}

t_plane	*listptr_to_plane(t_list *elem)
{
	return ((t_plane *)((t_object_node *)elem->content)->obj);
}

t_cylinder	*listptr_to_cylinder(t_list *elem)
{
	return ((t_cylinder *)((t_object_node *)elem->content)->obj);
}
