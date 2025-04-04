/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:54:09 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/03 12:05:22 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

void	tuple_print(t_tuple *tuple)
{
	if (!tuple)
		return ;
	if (tuple->w == 1)
		printf("POINT { x: %f, y: %f, z: %f, w: %d }\n",
			tuple->x, tuple->y, tuple->z, tuple->w);
	else if (tuple->w == 0)
		printf("VEC { x: %f, y: %f, z: %f, w: %d }\n",
			tuple->x, tuple->y, tuple->z, tuple->w);
	else
		printf("UNKNOWN { x: %f, y: %f, z: %f, w: %d }\n",
			tuple->x, tuple->y, tuple->z, tuple->w);
}
