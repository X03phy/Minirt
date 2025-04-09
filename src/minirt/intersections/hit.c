/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:58:56 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/08 15:31:26 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

// t_intersection2	**world_hit(t_config *c, t_ray r)
// {
// 	t_intersection2	**result;
// 	t_list			*tmp;
// 	double			t;
// 	int				i;
//
// 	if (!c)
// 		return (NULL);
// 	if (c->total_objects == 0)
// 		return (NULL);
// 	result = ft_calloc(sizeof(t_intersection2 *), c->total_objects + 1);
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	t = INFINITY;
// 	tmp = c->objects_list;
// 	while (tmp)
// 	{
//
// 		tmp = tmp->next;
// 	}
// 	return (result);
// }


t_intersection	*hit(t_config	*c, t_ray r)
{
	t_intersection	*result;
	t_list			*tmp;
	double			t;

	if (!c)
		return (NULL);
	if (c->total_objects == 0)
		return (NULL);
	result = ft_calloc(sizeof(t_intersection), 1);
	if (!result)
		return (NULL);
	result->t = INFINITY;
	result->object = NULL;
	tmp = c->objects_list;
	while (tmp)
	{
		if (((t_object_node *)tmp->content)->type == SPHERE)
		{
			if (ray_sphere_intersection((t_sphere *)(((t_object_node *)(tmp->content))->obj), r, &t))
			{
				if (t > 0 && t < result->t)
				{
					result->t = t;
					result->object = ((t_object_node *)(tmp->content))->obj;
					result->object->type = SPHERE;
				}
			}
		}
		else if (((t_object_node *)tmp->content)->type == PLANE)
		{
			if (ray_plane_intersection((t_plane *)(((t_object_node *)(tmp->content))->obj), r, &t))
			{
				if (t > 0 && t < result->t)
				{
					result->t = t;
					result->object = ((t_object_node *)(tmp->content))->obj;
					result->object->type = PLANE;
				}
			}
		}
		else if (((t_object_node *)tmp->content)->type == CYLINDER)
		{
			t_cylinder *cylinder = (t_cylinder *)(((t_object_node *)(tmp->content))->obj);
   			cylinder->orientation_vec = vector_normalize(cylinder->orientation_vec);
			if (ray_cylinder_intersection((t_cylinder *)(((t_object_node *)(tmp->content))->obj), r, &t))
			{
				// printf("hit : %f\n", t);
				if (t > 0 && t < result->t)
				{
					result->t = t;
					result->object = ((t_object_node *)(tmp->content))->obj;
					result->object->type = CYLINDER;
					
				}
			}
		}
		else if (((t_object_node *)tmp->content)->type == DISK)
		{
			if (ray_disk_intersection((t_disk *)(((t_object_node *)(tmp->content))->obj), r, &t))
			{
				if (t > 0 && t < result->t)
				{
					result->t = t;
					result->object = ((t_object_node *)(tmp->content))->obj;
					result->object->type = DISK;
				}
			}
		}
		tmp = tmp->next;
	}
	if (result->object)
		return (result);
	return (free(result), NULL);
}
