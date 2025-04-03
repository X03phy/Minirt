/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:54 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 14:52:59 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	parse_camera(t_config *c, char **infos)
{	
	if (c->camera != NULL)
	{
		c->err.msg = TOO_MANY_ELEMENT;
		return (false);
	}
	if (ft_tabsize(infos) != 8)
		return (false);
	c->camera = ft_calloc(sizeof(t_camera), 1);
	if (!c->camera)
		return (false);
	c->camera->position = new_point(ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	c->camera->orientation_vec = new_vec(ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6]));
	c->camera->fov = ft_atoi(infos[7]);
	return (true);
}
