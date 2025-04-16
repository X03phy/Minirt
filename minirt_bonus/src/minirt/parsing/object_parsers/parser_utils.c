/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:04:52 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 10:47:43 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minirt.h"

bool	check_only_valid_float(char **tab)
{
	if (!tab)
		return (false);
	while (*tab)
	{
		if (!ft_is_double(*tab) && ft_strcmp(*tab, "checked") != 0)
			return (false);
		tab++;
	}
	return (true);
}
