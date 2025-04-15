/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_substitute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:43:05 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/11 11:08:56 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	tuple_substitute(t_tuple a, t_tuple b)
{
	return (
		tuple_create(
			a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w
		)
	);
}
