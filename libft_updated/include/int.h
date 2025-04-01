/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:09:36 by ebonutto          #+#    #+#             */
/*   Updated: 2025/03/28 16:06:42 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

# include "char.h"
# include <stdlib.h>
# include "string.h"

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_swapi(int *a, int *b);

#endif
