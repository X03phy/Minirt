/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:22:59 by ebonutto          #+#    #+#             */
/*   Updated: 2025/03/28 15:55:32 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

char	**ft_tabdup(char **tab)
{
	char	**cpy;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
		{
			ft_dfree(&cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
