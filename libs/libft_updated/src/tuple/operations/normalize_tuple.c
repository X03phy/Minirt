/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:52:45 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 14:01:36 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	normalize_tuple(t_tuple a)
{
	return (
		new_tuple(
			a.x / mag_tuple(a),
			a.y / mag_tuple(a),
			a.z / mag_tuple(a),
			a.w / mag_tuple(a)
		)
	);
}
