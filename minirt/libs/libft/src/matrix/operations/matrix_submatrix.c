/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:20:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 11:04:21 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

static void	fill(t_matrix *res, t_matrix *m, int row, int col)
{	
	int			i;
	int			j;
	int			mi;
	int			mj;

	i = -1;
	mi = 0;
	while (++i < res->row && mi < m->row)
	{
		mj = 0;
		j = -1;
		if (mi == row)
			mi++;
		while (++j < res->col && mj < m->col)
		{
			if (mj == col)
				mj++;
			res->matrix[i][j] = m->matrix[mi][mj];
			mj++;
		}
		mi++;
	}
}

t_matrix	*matrix_submatrix(t_matrix *m, int row, int col)
{
	t_matrix	*res;

	if (!m)
		return (NULL);
	if (m->row != m->col)
		return (NULL);
	if (m->col == 1 && m->row == 1)
		return (matrix_new(1, 1, &m->matrix[0][0]));
	res = matrix_new(m->row - 1, m->col - 1, NULL);
	if (!res)
		return (NULL);
	fill(res, m, row, col);
	return (res);
}
