/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:26:54 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:27:31 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

double	cofactor_matrix(t_matrice *m, int row, int col)
{
	double	mat_minor;

	if (!m || row < 0 || col < 0)
		return (0);
	mat_minor = minor_matrix(m, row, col);
	if ((row + col) % 2)
		return (-mat_minor);
	return (mat_minor);
}
