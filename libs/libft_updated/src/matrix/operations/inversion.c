/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:48 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 10:51:56 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*inversion(t_matrice *m)
{
	t_matrice	*result;
	int			i;
	int			j;
	double		tmpcofactor;

	if (!m)
		return (NULL);
	if (det_matrix(m) == 0)
		return (NULL);
	result = new_matrix(m->row, m->col, NULL);
	i = - 1;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
		{
			tmpcofactor = cofactor_matrix(m, i, j);
			result->matrice[j][i] = tmpcofactor / det_matrix(m);
		}
	}
	return (result);
}
