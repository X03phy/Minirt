/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_matrices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:44:46 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 14:20:14 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

bool	equal_matrices(t_matrice *m1, t_matrice *m2)
{
	int	i;
	int	j;

	if (!m1 || !m2)
		return (false);
	if (m1->col != m2->col || m1->row != m2->row)
		return (false);
	i = -1;
	while (++i < m1->row)
	{
		j = -1;
		while (j++ < m1->col)
			if (m1->matrice[i][j] != m2->matrice[i][j])
				return (false);
	}
	return (true);
}
