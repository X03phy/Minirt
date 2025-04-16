/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:21 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 16:59:26 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_light(t_config *c, char **infos, int currline)
{
	t_list		*node;
	t_light		*light;

	if (!check_only_valid_float(&infos[1], 7))
	{
		c->err.msg = INVALID_NUMBER;
		c->err.line = currline;
		return (false);
	}
	if (ft_tabsize(infos) != 8)
		return (false);
	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
		return (false);
	light->position = point_create(
			ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	light->brightness = ft_atod(infos[4]);
	light->color = point_create(
			ft_atoi(infos[5]) / 255.0,
			ft_atoi(infos[6]) / 255.0, ft_atoi(infos[7]) / 255.0);
	node = ft_lstnew(light);
	if (!node)
		return (free(light), false);
	ft_lstadd_back(&c->spotlights, node);
	return (true);
}
