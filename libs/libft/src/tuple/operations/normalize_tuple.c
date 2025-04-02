/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:52:45 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 15:54:42 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	normalize_tuple(t_tuple a)
{
	double	magnitude;

	magnitude = mag_tuple(a);
	if (magnitude == 0)
		return new_tuple(0, 0, 0, a.w);
		return new_tuple(a.x / magnitude, a.y / magnitude, a.z / magnitude, a.w / magnitude);
}
