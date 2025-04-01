/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:44:12 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:29:12 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

double	minor_matrix(t_matrice *m, int row, int col)
{
	t_matrice	*sub;
	double		det;

	if (!m)
		return (0);
	sub = submatrix(m, row, col);
	det = det_matrix(sub);
	clean_matrix(&sub);
	return (det);
}
