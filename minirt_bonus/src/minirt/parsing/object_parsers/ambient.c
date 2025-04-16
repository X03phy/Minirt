/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:07:04 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 16:59:46 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_ambient(t_config *c, char **infos, int currline)
{
	if (c->ambient_light != NULL)
	{
		c->err.msg = TOO_MANY_ELEMENT;
		return (false);
	}
	if (ft_tabsize(infos) != 5)
		return (false);
	if (!check_only_valid_float(&infos[1], 4))
	{
		c->err.msg = INVALID_NUMBER;
		c->err.line = currline;
		return (false);
	}
	c->ambient_light = ft_calloc(sizeof(t_ambient_light), 1);
	if (!c->ambient_light)
		return (false);
	c->ambient_light->ratio = ft_atod(infos[1]);
	c->ambient_light->color = point_create(
			ft_atoi(infos[2]) / 255.0, ft_atoi(infos[3])
			/ 255.0, ft_atoi(infos[4]) / 255.0);
	return (true);
}
