/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:45:28 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 11:47:20 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/int.h"
#include <math.h>

double	ft_atof(const char *nptr)
{
	int		i;
	int		j;
	int		flag;
	double	val;
	int		sign;

	i = 0;
	j = 0;
	sign = 1;
	val = (double)ft_atoi(nptr);
	if (*nptr == '-' && val >= 0)
		sign = -1;
	flag = 1;
	while (nptr[i] && nptr[i] != '.')
		i++;
	i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		val = (val * 10) + (nptr[i] - '0');
		if (flag == 1)
			j--;
		i++;
	}
	return (sign * (val * pow(10, j)));
}
