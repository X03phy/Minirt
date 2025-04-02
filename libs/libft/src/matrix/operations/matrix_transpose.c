/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:58:24 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:43:27 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_transpose(t_matrix	*m)
{
	int			i;
	int			j;
	t_matrix	*res;

	if (!m)
		return (NULL);
	res = matrix_new(m->col, m->row, NULL);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < res->row)
	{
		j = -1;
		while (++j < res->col)
		{
			res->matrix[i][j] = m->matrix[j][i];
		}
	}
	return (res);
}
