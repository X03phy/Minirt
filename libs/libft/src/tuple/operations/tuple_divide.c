/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:30:38 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 14:01:36 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	tuple_divide(t_tuple a, double factor)
{
	return (
		tuple_create(
			a.x / factor, a.y / factor, a.z / factor, a.w / factor
		)
	);
}
