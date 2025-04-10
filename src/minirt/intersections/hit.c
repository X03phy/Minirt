/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:58:56 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/10 09:52:35 by maecarva         ###   ########.fr       */
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

bool is_in_shadow(t_config *c, t_tuple xpoint, int id)
{
    if (id == -1)
        return false;
    t_tuple v = tuple_substitute(c->light->position, xpoint);
    double distance = vector_magnitude(v);
    t_tuple direction = vector_normalize(v);
    t_tuple offset_point = tuple_add(xpoint, tuple_multiply(direction, ACNE_DECALAGE));
    t_ray ray_to_light = ray_create(offset_point, direction);
    t_intersection *xs = hit(c, ray_to_light);
    if (xs)
    {
        int xsid = get_obj_id(xs->object);
        if (xsid == id)
            return (free(xs), false);
        if (xs->t < distance)
            return (free(xs), true);
    }
    return (free(xs), false);
}


t_intersection	*hit(t_config	*c, t_ray r)
{
	t_intersection	*result;
	t_list			*tmp;
	double			t;
	bool			intersection_found;

	if (!c)
		return (NULL);
	if (c->total_objects == 0)
		return (NULL);
	result = ft_calloc(sizeof(t_intersection), 1);
	if (!result)
		return (NULL);
	result->t = INFINITY;
	result->object = NULL;
	intersection_found = false;
	tmp = c->objects_list;
	while (tmp)
	{
		intersection_found = false;
		if (((t_object_node *)tmp->content)->type == SPHERE)
			intersection_found = ray_sphere_intersection((t_sphere *)(((t_object_node *)(tmp->content))->obj), r, &t);
		else if (((t_object_node *)tmp->content)->type == PLANE)
			intersection_found = ray_plane_intersection((t_plane *)(((t_object_node *)(tmp->content))->obj), r, &t);
		else if (((t_object_node *)tmp->content)->type == CYLINDER)
		{
			t_cylinder *cylinder = (t_cylinder *)(((t_object_node *)(tmp->content))->obj);
   			cylinder->orientation_vec = vector_normalize(cylinder->orientation_vec);
			intersection_found = ray_cylinder_intersection((t_cylinder *)(((t_object_node *)(tmp->content))->obj), r, &t);
		}
		else if (((t_object_node *)tmp->content)->type == DISK)
			intersection_found = ray_disk_intersection((t_disk *)(((t_object_node *)(tmp->content))->obj), r, &t);

		if (intersection_found && t > 0 && t < result->t)
		{
			result->t = t;
			result->object = ((t_object_node *)tmp->content);
			result->object->type = get_type(result->object);
		}
		tmp = tmp->next;
	}
	if (result->object)
		return (result);
	return (free(result), NULL);
}
