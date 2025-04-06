/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_mult_tuple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:41:51 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/06 11:43:32 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	tuple_mult_tuple(t_tuple a, t_tuple b)
{
	return (
		tuple_create(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w)
	);
}
