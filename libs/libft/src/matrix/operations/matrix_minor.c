/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:44:12 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:41:13 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

double	matrix_minor(t_matrix *m, int row, int col)
{
	t_matrix	*sub;
	double		det;

	if (!m)
		return (0);
	sub = matrix_submatrix(m, row, col);
	det = matrix_determinant(sub);
	matrix_free(&sub);
	return (det);
}
