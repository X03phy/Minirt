/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:20:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:31:03 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*submatrix(t_matrice *m, int row, int col)
{
	t_matrice	*res;
	int			i;
	int			j;
	int			mi;
	int			mj;

	if (!m)
		return (NULL);
	if (m->row != m->col)
		return (NULL);
	if (m->col == 1 && m->row == 1)
		return (new_matrix(1, 1, &m->matrice[0][0]));
	res = new_matrix(m->row - 1, m->col - 1, NULL);
	if (!res)
		return (NULL);
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
			res->matrice[i][j] = m->matrice[mi][mj];
			mj++;
		}
		mi++;
	}
	return (res);
}
