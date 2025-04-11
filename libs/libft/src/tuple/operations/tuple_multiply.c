/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_multiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:46:17 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/11 11:08:37 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	tuple_multiply(t_tuple a, double factor)
{
	return (
		tuple_create(
			a.x * factor, a.y * factor, a.z * factor, a.w * factor
		)
	);
}
