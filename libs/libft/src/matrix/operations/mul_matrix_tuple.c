/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply_tuple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:16:02 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 15:29:39 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_tuple	matrix_multiply_tuple(t_matrix *m, t_tuple t)
{
	t_tuple		result;
	t_matrix	*m2;
	t_matrix	*m3;

	if (!m)
		new_tuple(0, 0, 0, POINT);
	m2 = matrix_new(m->row, 1, (double []){t.x, t.y, t.z, t.w});
	m3 = matrix_multiply(m, m2);
	result = new_tuple(m3->matrix[0][0],
			m3->matrix[1][0],
			m3->matrix[2][0],
			m3->matrix[3][0]);
	return (matrix_free(&m2), matrix_free(&m3), result);
}
