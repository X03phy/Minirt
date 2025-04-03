/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:07:13 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 19:08:22 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

bool	check_config(t_config *config)
{
	bool	status;

	status = true;
	if (!config)
		return (false);
	if (!config->ambient_light || !config->camera || !config->light)
	{
		if (!config->ambient_light)
			config->err.msg = "No ambient light !\n";
		else if (!config->camera)
			config->err.msg = "No camera !\n";
		else if (!config->light)
			config->err.msg = "No spotlight !\n";
		status = false;
	}
	// if (status && (config->win_height <= 0 || config->win_width <= 0))
	// {
	// 	config->err.msg = "Invalid image size !\n";
	// 	status = false;
	// }
	return (status);
}
