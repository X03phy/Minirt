/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:37:25 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 13:34:26 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/string.h"

int	ft_strcmp(char *src1, char *src2)
{
	int	i;

	i = 0;
	while (src1[i] && src1[i] == src2[i])
		i++;
	return (src1[i] - src2[i]);
}
