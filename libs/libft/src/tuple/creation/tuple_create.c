/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:39:03 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/11 11:07:03 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	tuple_create(double x, double y, double z, int w)
{
	return ((t_tuple){.x = x, .y = y, .z = z, .w = w});
}
