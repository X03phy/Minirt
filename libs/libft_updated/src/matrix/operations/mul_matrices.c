/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_matrices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:03 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:29:24 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*mul_matrices(t_matrice *m1, t_matrice *m2)
{
	t_matrice	*m3;
	int			i;
	int			j;
	int			k;

	if (!m1 || !m2)
		return (NULL);
	m3 = new_matrix(m1->row, m2->col, NULL);
	if (!m3)
		return (NULL);
	i = -1;
	while (++i < m1->row)
	{
		j = -1;
		while (++j < m2->col)
		{
			k = -1;
			while (++k < m1->col)
				m3->matrice[i][j] += m1->matrice[i][k] * m2->matrice[k][j];
		}
	}
	return (m3);
}
