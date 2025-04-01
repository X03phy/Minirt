/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_charset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:09:19 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 13:34:26 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/string.h"

bool	ft_str_charset(char *str, char *charset)
{
	while (*str)
	{
		if (ft_char_charset(*str, charset) == false)
			return (false);
		str++;
	}
	return (true);
}
