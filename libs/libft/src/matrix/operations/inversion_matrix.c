/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:48 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:43:27 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_inverse(t_matrix *m)
{
	t_matrix	*result;
	int			i;
	int			j;
	double		tmpcofactor;

	if (!m)
		return (NULL);
	if (matrix_determinant(m) == 0)
		return (NULL);
	result = matrix_new(m->row, m->col, NULL);
	i = - 1;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
		{
			tmpcofactor = matrix_cofactor(m, i, j);
			result->matrix[j][i] = tmpcofactor / matrix_determinant(m);
		}
	}
	return (result);
}
