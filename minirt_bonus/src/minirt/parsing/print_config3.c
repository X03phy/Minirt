/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:57:39 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/17 16:58:10 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	print_lights(t_list *spotlights)
{
	t_list	*tmp;

	if (!spotlights)
		return ;
	tmp = spotlights;
	while (tmp)
	{
		print_light((t_light *)tmp->content);
		tmp = tmp->next;
	}
}
