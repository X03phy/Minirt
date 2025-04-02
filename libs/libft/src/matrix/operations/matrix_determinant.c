/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:35 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:27:58 by ebonutto         ###   ########.fr       */
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
	// Expansion par cofacteurs sur la première ligne (ligne 0)
	while (++j < m->col)
	{
		// On crée la sous-matrix en retirant la ligne 0 et la colonne j
		sub = matrix_submatrix(m, 0, j);
		// Calcul récursif du déterminant de la sous-matrix
		subdet = matrix_determinant(sub);
		if (j % 2 == 0)
			det += m->matrix[0][j] * subdet;
		else
			det += -1 * m->matrix[0][j] * subdet;
		matrix_free(&sub);
	}
	return (det);
}
