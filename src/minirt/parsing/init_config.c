/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:28:30 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 14:11:46 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_config	*init_config(void)
{
	t_config	*c;

	c = ft_calloc(sizeof(t_config), 1);
	if (!c)
		return (NULL);
	c->funcs = ft_calloc(sizeof(parsefunc), SCENE_TYPE_NUM);
	if (!c->funcs)
		return (ft_sfree((void **)&c), NULL);
	c->funcs[0] = (parsefunc)parse_ambient;
	c->funcs[1] = (parsefunc)parse_camera;
	c->funcs[2] = (parsefunc)parse_light;
	c->funcs[3] = (parsefunc)parse_sphere;
	c->funcs[4] = (parsefunc)parse_plan;
	c->funcs[5] = (parsefunc)parse_cylinder;
	return (c);
}
