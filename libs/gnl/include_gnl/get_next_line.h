/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x03phy <x03phy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:56:23 by ebonutto          #+#    #+#             */
/*   Updated: 2025/02/02 22:21:30 by x03phy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/include/libft.h"

# define ERROR_CODE 42

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

int		get_next_line(int fd, char **line);

int		ft_isline(char *str);

#endif
