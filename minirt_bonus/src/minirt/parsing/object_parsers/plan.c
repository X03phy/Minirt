/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:02 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/17 17:02:48 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

static bool	handle_more_args_plane(t_config *c, char **infos, t_plane *p)
{
	char	*tmp;

	tmp = NULL;
	if (infos[10] && ft_strcmp("checked", infos[10]) == 0)
		p->checked = true;
	else if (ft_strnstr(infos[10], "text", ft_strlen(infos[10])) == infos[10])
	{
		tmp = ft_strchr(infos[10], ':');
		if (!tmp)
			return (false);
		tmp = ft_strdup(tmp + 1);
		if (!tmp || ft_strlen(tmp) == 0)
			return (free(tmp), false);
		p->textured = true;
		p->texture_name = tmp;
		p->texture.img = mlx_xpm_file_to_image(c->mlx,
				tmp, &p->texture.imgw, &p->texture.imgh);
		if (!p->texture.img)
			return (false);
		p->texture.addr = mlx_get_data_addr(p->texture.img,
				&p->texture.bits_per_pixels,
				&p->texture.line_len, &p->texture.endian);
		if (!p->texture.addr)
			return (false);
	}
	else
		return (false);
	return (true);
}

static bool	fill_plan(t_config *c, char **infos, t_object_node *node)
{
	((t_plane *)node->obj)->id = ++(c->total_objects);
	((t_plane *)node->obj)->center = point_create(
			ft_atod(infos[1]), ft_atod(infos[2]), ft_atod(infos[3]));
	((t_plane *)node->obj)->orientation_vec = vector_normalize(vector_create(
				ft_atod(infos[4]), ft_atod(infos[5]), ft_atod(infos[6])));
	((t_plane *)node->obj)->color = point_create(
			ft_atoi(infos[7]) / 255.0,
			ft_atoi(infos[8]) / 255.0, ft_atoi(infos[9]) / 255.0);
	((t_plane *)node->obj)->material = default_material(
			((t_plane *)node->obj)->color);
	((t_plane *)node->obj)->material.specular = 0.1;
	((t_plane *)node->obj)->material.shininess = 10.0;
	if (infos[10])
	{
		if (!handle_more_args_plane(c, infos, (t_plane *)node->obj))
			return (false);
	}
	return (true);
}

bool	parse_plan(t_config *c, char **infos, int currline)
{
	t_object_node	*node;
	t_list			*lsttmp;

	if (ft_tabsize(infos) != 10 && ft_tabsize(infos) != 11)
		return (false);
	if (!check_only_valid_float(&infos[1], 9))
	{
		c->err.msg = INVALID_NUMBER;
		c->err.line = currline;
		return (false);
	}
	node = ft_calloc(sizeof(t_object_node), 1);
	if (!node)
		return (false);
	node->type = PLANE;
	node->obj = ft_calloc(sizeof(t_plane), 1);
	if (!node->obj)
		return (free(node), false);
	if (!fill_plan(c, infos, node))
		return (free(node->obj), free(node), false);
	lsttmp = ft_lstnew(node);
	if (!lsttmp)
		return (free(node->obj), free(node), false);
	ft_lstadd_back(&c->objects_list, lsttmp);
	return (true);
}
