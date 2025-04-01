/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:19:07 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 15:32:07 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*clean_matrix(t_matrice **m)
{
	int	j;

	if (!m || !*m)
		return (NULL);
	j = 0;
	while (j < (*m)->row)
	{
		ft_sfree((void **)&(*m)->matrice[j]);
		j++;
	}
	ft_sfree((void **)&(*m)->matrice);
	free(*m);
	return (NULL);
}
