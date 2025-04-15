/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:03:59 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 13:34:09 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/safe.h"

void	ft_error(char *str, int exit_status)
{
	ft_putendl_fd(str, 2);
	exit(exit_status);
}
