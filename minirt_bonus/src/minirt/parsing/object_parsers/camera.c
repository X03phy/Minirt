/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:54 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 09:24:56 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_camera(t_config *c, char **infos, int currline)
{
	if (c->camera != NULL)
	{
		c->err.msg = TOO_MANY_ELEMENT;
		return (false);
	}
	if (!check_only_valid_float(&infos[1]))
	{
		c->err.msg = INVALID_NUMBER;
		c->err.line = currline;
		return (false);
	}
	if (ft_tabsize(infos) != 8)
		return (false);
	c->camera = ft_calloc(sizeof(t_camera), 1);
	if (!c->camera)
		return (false);
	c->camera->position = point_create(
			ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	c->camera->orientation_vec = vector_normalize(vector_create(
			ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6])));
	c->camera->fov = ft_atoi(infos[7]);
	return (true);
}
