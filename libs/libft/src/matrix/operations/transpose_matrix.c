/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:58:24 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:31:22 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*transpose_matrix(t_matrice	*m)
{
	int			i;
	int			j;
	t_matrice	*res;

	if (!m)
		return (NULL);
	res = new_matrix(m->col, m->row, NULL);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < res->row)
	{
		j = -1;
		while (++j < res->col)
		{
			res->matrice[i][j] = m->matrice[j][i];
		}
	}
	return (res);
}
