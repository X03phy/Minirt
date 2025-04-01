/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:13:29 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:25:41 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*fill_matrix(t_matrice *m, double *values)
{
	int	i;
	int	j;

	if (!m || !values)
		return (m);
	i = -1;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
			m->matrice[i][j] = *values++;
	}
	return (m);
}

t_matrice	*new_matrix(int row, int col, double *value)
{
	t_matrice	*m;
	int			i;

	m = ft_calloc(sizeof(t_matrice), 1);
	if (!m)
		return (NULL);
	m->col = col;
	m->row = row;
	m->matrice = ft_calloc(sizeof(double *), row);
	if (!m->matrice)
		return (ft_sfree((void **)&m), NULL);
	i = -1;
	while (++i < row)
	{
		m->matrice[i] = ft_calloc(sizeof(double), col);
		if (!m->matrice[i])
			return (clean_matrix(&m));
	}
	if (value)
		return (fill_matrix(m, value));
	return (m);
}
