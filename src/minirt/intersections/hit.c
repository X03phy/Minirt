/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:58:56 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 11:00:30 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

// t_intersection	*world_hit(t_config *c, t_ray r)
// {
// 	t_intersection	**result;
// 	t_list			*tmp;
// 	double			t;
// 	int				i;
//
// 	if (!c)
// 		return (NULL);
// 	if (c->total_objects == 0)
// 		return (NULL);
// 	result = ft_calloc(sizeof(t_intersection *), c->total_objects + 1);
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
// 	
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
				}
			}
		}
		tmp = tmp->next;
	}
	if (result->object)
		return (result);
	return (free(result), NULL);
}
