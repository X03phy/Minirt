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
	if (!config)
		return (false);
	if (!config->ambient_light || !config->camera || !config->light)
		return (false);

	return (true);
}
