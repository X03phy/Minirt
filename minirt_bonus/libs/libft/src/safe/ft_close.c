/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:17 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 13:34:09 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/safe.h"

void	ft_close(int *fd)
{
	if (*fd > 2)
	{
		close(*fd);
		*fd = -1;
	}
}
