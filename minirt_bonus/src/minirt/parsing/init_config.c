/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:28:30 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/13 16:52:04 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_config	*init_config(int ac, char **av)
{
	t_config	*c;

	c = ft_calloc(sizeof(t_config), 1);
	if (!c)
		return (NULL);
	c->funcs = ft_calloc(sizeof(t_parsefunc), SCENE_TYPE_NUM);
	if (!c->funcs)
		return (ft_sfree((void **)&c), NULL);
	c->funcs[0] = (t_parsefunc)parse_ambient;
	c->funcs[1] = (t_parsefunc)parse_camera;
	c->funcs[2] = (t_parsefunc)parse_light;
	c->funcs[3] = (t_parsefunc)parse_sphere;
	c->funcs[4] = (t_parsefunc)parse_plan;
	c->funcs[5] = (t_parsefunc)parse_cylinder;
	c->funcs[6] = (t_parsefunc)parse_cone;
	c->ac = ac;
	c->av = av;
	c->err.line = -1;
	c->win_height = WINH;
	c->win_width = WINW;
	return (c);
}
