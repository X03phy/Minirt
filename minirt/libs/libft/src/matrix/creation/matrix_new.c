/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:13:29 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:43:27 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*fill_matrix(t_matrix *m, double *values)
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
			m->matrix[i][j] = *values++;
	}
	return (m);
}

t_matrix	*matrix_new(int row, int col, double *value)
{
	t_matrix	*m;
	int			i;

	m = ft_calloc(sizeof(t_matrix), 1);
	if (!m)
		return (NULL);
	m->col = col;
	m->row = row;
	m->matrix = ft_calloc(sizeof(double *), row);
	if (!m->matrix)
		return (ft_sfree((void **)&m), NULL);
	i = -1;
	while (++i < row)
	{
		m->matrix[i] = ft_calloc(sizeof(double), col);
		if (!m->matrix[i])
			return (matrix_free(&m));
	}
	if (value)
		return (fill_matrix(m, value));
	return (m);
}
