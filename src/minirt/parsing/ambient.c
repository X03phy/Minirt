/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:07:04 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 14:49:07 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

bool	parse_ambient(t_config *c, char **infos)
{
	if (ft_tabsize(infos) != 5)
		return (false);
	c->ambient_light = ft_calloc(sizeof(t_ambient_light), 1);
	if (!c->ambient_light)
		return (false);
	c->ambient_light->ratio = ft_atod(infos[1]);
	c->ambient_light->color = (0 << 24 | ft_atoi(infos[2]) << 16 | ft_atoi(infos[3]) << 8 | ft_atoi(infos[4]));
	return (true);
}
