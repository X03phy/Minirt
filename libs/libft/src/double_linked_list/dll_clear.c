/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:41:56 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 13:30:28 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/double_linked_list.h"

void	dll_clear(t_dlist **dlist)
{
	t_dlist	*tmp;
	int		size;

	size = dll_size(dlist);
	tmp = *dlist;
	while (size > 0)
	{
		tmp = tmp->next;
		free((*dlist)->content);
		free(*dlist);
		*dlist = tmp;
		size--;
	}
	*dlist = NULL;
}
