/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:52:45 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 16:31:19 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	vector_normalize(t_tuple a)
{
	double	magnitude;

	magnitude = vector_magnitude(a);
	if (magnitude == 0)
		return tuple_create(0, 0, 0, a.w);
	return tuple_create(a.x / magnitude, a.y / magnitude, a.z / magnitude, a.w / magnitude);
}
