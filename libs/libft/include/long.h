/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:11:49 by ebonutto          #+#    #+#             */
/*   Updated: 2025/03/28 16:06:49 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include <stdbool.h>
# include "char.h"
# include <limits.h>

long	ft_atol(const char *str);
bool	ft_islong(char *str);

#endif
