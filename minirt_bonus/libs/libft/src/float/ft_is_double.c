/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:08:41 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/05 10:48:45 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/float.h"
#include "../../include/char.h"
#include <stdbool.h>

bool	ft_is_double(char *s)
{
	int	totalp;
	int	i;

	i = 0;
	totalp = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == '.')
			return (false);
		if (i == 0 && ft_issign(s[i]))
			i++;
		if (s[i] == '.')
			totalp++;
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return (false);
		i++;
	}
	return (true);
}
