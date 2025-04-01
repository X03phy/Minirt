/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:35 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:27:58 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

double	det_matrix(t_matrice *m)
{
	int			j;
	double		det;
	t_matrice	*sub;
	double		subdet;

	if (!m || m->row != m->col)
		return (0);
	if (m->row == 1)
		return (m->matrice[0][0]);
	if (m->row == 2)
		return (m->matrice[0][0] * m->matrice[1][1]
			- m->matrice[0][1] * m->matrice[1][0]);
	det = 0;
	j = -1;
	// Expansion par cofacteurs sur la première ligne (ligne 0)
	while (++j < m->col)
	{
		// On crée la sous-matrice en retirant la ligne 0 et la colonne j
		sub = submatrix(m, 0, j);
		// Calcul récursif du déterminant de la sous-matrice
		subdet = det_matrix(sub);
		if (j % 2 == 0)
			det += m->matrice[0][j] * subdet;
		else
			det += -1 * m->matrice[0][j] * subdet;
		clean_matrix(&sub);
	}
	return (det);
}
