/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_tuple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:46:17 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 14:01:36 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	mul_tuple(t_tuple a, double factor)
{
	return (
		new_tuple(
			a.x * factor, a.y * factor, a.z * factor, a.w * factor
		)
	);
}
