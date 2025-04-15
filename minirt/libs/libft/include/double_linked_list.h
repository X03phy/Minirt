/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:39:09 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 13:37:24 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include <stdlib.h>
# include "memory.h"

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

t_dlist	*dll_add_back(t_dlist **dlist, t_dlist *new_elem);
void	dll_clear(t_dlist **dlist);
void	dll_insert(t_dlist *l1, t_dlist *l2);
t_dlist	*dll_new(void *content);
int		dll_size_between(t_dlist *start, t_dlist *end);
int		dll_size(t_dlist **dlist);

#endif
