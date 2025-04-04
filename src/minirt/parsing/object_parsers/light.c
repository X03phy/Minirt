/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:21 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/03 11:28:47 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_light(t_config *c, char **infos)
{
	if (c->light != NULL)
	{
		c->err.msg = TOO_MANY_ELEMENT;
		return (false);
	}
	if (ft_tabsize(infos) != 8)
		return (false);
	c->light = ft_calloc(sizeof(t_light), 1);
	if (!c->light)
		return (false);
	c->light->position = point_create(ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	c->light->brightness = ft_atod(infos[4]);
	c->light->color = new_point(ft_atoi(infos[5]) / 255.0, ft_atoi(infos[6]) / 255.0, ft_atoi(infos[7]) / 255.0);
	return (true);
}
