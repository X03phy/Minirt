/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:07:13 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/13 15:10:41 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	check_camera(t_config *config)
{
	if (config->camera->fov <= 0 || config->camera->fov >= 180)
	{
		config->err.msg = "Invalid camera FOV!\n";
		return (false);
	}
	if (invalid_vec(config->camera->orientation_vec))
	{
		config->err.msg = "Invalid camera vector!\n";
		return (false);
	}
	return (true);
}

bool	check_one(t_config *config)
{
	if (!config)
		return (false);
	if (config->err.msg != NULL)
		return (false);
	if (config->objects_list == NULL || config->total_objects == 0)
	{
		config->err.msg = "No object to display.\n";
		return (false);
	}
	if (!config->ambient_light || !config->camera || !config->light)
	{
		if (!config->ambient_light)
			config->err.msg = "No ambient light !\n";
		else if (!config->camera)
			config->err.msg = "No camera !\n";
		else if (!config->light)
			config->err.msg = "No spotlight !\n";
		return (false);
	}
	return (true);
}

bool	check_config(t_config *config)
{
	if (check_one(config) == false)
		return (false);
	if (check_vectors(config))
	{
		config->err.msg = "Invalid vector!\n";
		return (false);
	}
	if (size_checks(config))
	{
		config->err.msg = "Invalid size or radius value!\n";
		return (false);
	}
	if (check_colors_error(config))
	{
		config->err.msg = "Invalid color !\n";
		return (false);
	}
	return (true);
}
