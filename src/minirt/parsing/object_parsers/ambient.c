/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:07:04 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/04 12:24:28 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_ambient(t_config *c, char **infos)
{
	if (c->ambient_light != NULL)
	{
		c->err.msg = TOO_MANY_ELEMENT;
		return (false);
	}
	if (ft_tabsize(infos) != 5)
		return (false);
	c->ambient_light = ft_calloc(sizeof(t_ambient_light), 1);
	if (!c->ambient_light)
		return (false);
	c->ambient_light->ratio = ft_atod(infos[1]);
	c->ambient_light->color = point_create(ft_atoi(infos[2]) / 255.0, ft_atoi(infos[3]) / 255.0, ft_atoi(infos[4]) / 255.0);
	return (true);
}
