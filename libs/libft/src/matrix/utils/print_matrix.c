/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:33:52 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:43:27 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

int	num_digit(double n)
{
	int	n2;
	int	digit;

	digit = 0;
	if (n <= 0)
		digit = 1;
	n2 = (int)fabs(n);
	while (n2)
	{
		digit++;
		n2 /= 10;
	}
	return (digit);
}

bool	get_max(t_matrix *m, double *max)
{
	double	tmpmax;
	double	tmpmin;
	int		i;
	int		j;

	if (!m || !max)
		return (false);
	i = -1;
	tmpmax = m->matrix[0][0];
	tmpmin = tmpmax;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
		{
			if (m->matrix[i][j] > tmpmax)
				tmpmax = m->matrix[i][j];
			if (m->matrix[i][j] < tmpmin)
				tmpmin = m->matrix[i][j];
		}
	}
	*max = tmpmax;
	if (num_digit(tmpmin) > num_digit(tmpmax))
		*max = tmpmin;
	return (true);
}

void	print_element(double value, int max_digit)
{
	int	spaces;

	printf("| %.3f", value);
	spaces = max_digit - num_digit(value);
	while (spaces-- >= 0)
		printf(" ");
}

void	matrix_print(t_matrix *m)
{
	int		i;
	int		j;
	double	max;

	if (!m)
		return ;
	printf("matrix[%d][%d] ([row][col]):\n", m->row, m->col);
	i = -1;
	if (!get_max(m, &max))
		return ;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
		{
			print_element(m->matrix[i][j], num_digit(max));
		}
		printf("|\n");
	}
	printf("\n");
}
