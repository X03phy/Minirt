/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:03 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 11:01:22 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_multiply(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*m3;
	int			i;
	int			j;
	int			k;

	if (!m1 || !m2)
		return (NULL);
	m3 = matrix_new(m1->row, m2->col, NULL);
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
				m3->matrix[i][j] += m1->matrix[i][k] * m2->matrix[k][j];
		}
	}
	return (m3);
}
