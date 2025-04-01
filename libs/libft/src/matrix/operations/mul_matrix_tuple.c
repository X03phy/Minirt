/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_matrix_tuple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:16:02 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 15:29:39 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_tuple	mul_matrix_tuple(t_matrice *m, t_tuple t)
{
	t_tuple		result;
	t_matrice	*m2;
	t_matrice	*m3;

	if (!m)
		new_tuple(0, 0, 0, POINT);
	m2 = new_matrix(m->row, 1, (double []){t.x, t.y, t.z, t.w});
	m3 = mul_matrices(m, m2);
	result = new_tuple(m3->matrice[0][0],
			m3->matrice[1][0],
			m3->matrice[2][0],
			m3->matrice[3][0]);
	return (clean_matrix(&m2), clean_matrix(&m3), result);
}
