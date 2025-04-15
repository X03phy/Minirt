/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:35 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 10:33:23 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

double	matrix_determinant(t_matrix *m)
{
	int			j;
	double		det;
	t_matrix	*sub;
	double		subdet;

	if (!m || m->row != m->col)
		return (0);
	if (m->row == 1)
		return (m->matrix[0][0]);
	if (m->row == 2)
		return (m->matrix[0][0] * m->matrix[1][1]
			- m->matrix[0][1] * m->matrix[1][0]);
	det = 0;
	j = -1;
	while (++j < m->col)
	{
		sub = matrix_submatrix(m, 0, j);
		subdet = matrix_determinant(sub);
		if (j % 2 == 0)
			det += m->matrix[0][j] * subdet;
		else
			det += -1 * m->matrix[0][j] * subdet;
		matrix_free(&sub);
	}
	return (det);
}
