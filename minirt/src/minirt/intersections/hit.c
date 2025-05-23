/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:58:56 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 11:57:09 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <stdint.h>

int	get_obj_id(t_object_node *obj)
{
	if (!obj)
		return (-1);
	if (obj->obj == NULL)
		return (-1);
	if (obj->type == SPHERE)
		return (((t_sphere *)obj->obj)->id);
	else if (obj->type == CYLINDER)
		return (((t_cylinder *)obj->obj)->id);
	else if (obj->type == PLANE)
		return (((t_plane *)obj->obj)->id);
	else if (obj->type == DISK)
		return (((t_disk *)obj->obj)->id);
	return (-1);
}

t_object_type	get_type(t_object_node *obj)
{
	return (obj->type);
}

static void	hit_loop_result(t_intersection	*result, t_list *tmp,
	double t, bool intersection_found)
{
	if (intersection_found && t > 0 && t < result->t)
	{
		result->t = t;
		result->object = ((t_object_node *)tmp->content);
		result->object->type = get_type(result->object);
	}
}

static void	hit_loop(t_intersection	*result, t_list *tmp, t_ray r)
{
	bool		intersection_found;
	t_cylinder	*cylinder;
	double		t;

	t = 0;
	intersection_found = false;
	if (((t_object_node *)tmp->content)->type == SPHERE)
		intersection_found = ray_sphere_intersection(
				(t_sphere *)(((t_object_node *)(tmp->content))->obj), r, &t);
	else if (((t_object_node *)tmp->content)->type == PLANE)
		intersection_found = ray_plane_intersection(
				(t_plane *)(((t_object_node *)(tmp->content))->obj), r, &t);
	else if (((t_object_node *)tmp->content)->type == CYLINDER)
	{
		cylinder = (t_cylinder *)(((t_object_node *)(tmp->content))->obj);
			cylinder->orientation_vec = vector_normalize(
				cylinder->orientation_vec);
		intersection_found = ray_cylinder_intersection((t_cylinder *)(
					((t_object_node *)(tmp->content))->obj), r, &t);
	}
	else if (((t_object_node *)tmp->content)->type == DISK)
		intersection_found = ray_disk_intersection(
				(t_disk *)(((t_object_node *)(tmp->content))->obj), r, &t);
	hit_loop_result(result, tmp, t, intersection_found);
}

t_intersection	*hit(t_config	*c, t_ray r)
{
	t_intersection	*result;
	t_list			*tmp;

	if (!c || c->total_objects == 0)
		return (NULL);
	result = ft_calloc(sizeof(t_intersection), 1);
	if (!result)
		return (NULL);
	result->t = INFINITY;
	result->object = NULL;
	tmp = c->objects_list;
	while (tmp)
	{
		hit_loop(result, tmp, r);
		tmp = tmp->next;
	}
	if (result->object)
		return (result);
	return (free(result), NULL);
}
