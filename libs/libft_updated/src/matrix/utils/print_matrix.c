/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:33:52 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 14:21:47 by ebonutto         ###   ########.fr       */
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

bool	get_max(t_matrice *m, double *max)
{
	double	tmpmax;
	double	tmpmin;
	int		i;
	int		j;

	if (!m || !max)
		return (false);
	i = -1;
	tmpmax = m->matrice[0][0];
	tmpmin = tmpmax;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
		{
			if (m->matrice[i][j] > tmpmax)
				tmpmax = m->matrice[i][j];
			if (m->matrice[i][j] < tmpmin)
				tmpmin = m->matrice[i][j];
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

void	print_matrix(t_matrice *m)
{
	int		i;
	int		j;
	double	max;

	if (!m)
		return ;
	printf("Matrice[%d][%d] ([row][col]):\n", m->row, m->col);
	i = -1;
	if (!get_max(m, &max))
		return ;
	while (++i < m->row)
	{
		j = -1;
		while (++j < m->col)
		{
			print_element(m->matrice[i][j], num_digit(max));
		}
		printf("|\n");
	}
	printf("\n");
}
