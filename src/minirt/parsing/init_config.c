/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:28:30 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:33:00 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_config	*init_config(void)
{
	t_config	*c;

	c = ft_calloc(sizeof(t_config), 1);
	if (!c)
		return (NULL);
	return (c);
}
