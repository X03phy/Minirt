/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_occurence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:52:30 by maecarva          #+#    #+#             */
/*   Updated: 2025/03/28 12:36:16 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

int	ft_char_occurence(char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
