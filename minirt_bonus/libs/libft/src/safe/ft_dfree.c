/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:10:43 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 15:26:39 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/safe.h"

void	ft_dfree(char ***split)
{
	int	i;

	if (split && *split)
	{
		i = 0;
		while ((*split)[i])
		{
			free((*split)[i]);
			i++;
		}
		free(*split);
		*split = NULL;
	}
}
