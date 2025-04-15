/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:25:01 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 14:19:53 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include <stdlib.h>
# include "string.h"
# include "safe.h"

char	**ft_split_charset(char *str, char *charset);
char	**ft_split(char const *s, char c);
char	**ft_tabdup(char **tab);
int		ft_tabsize(char **tab);

#endif
