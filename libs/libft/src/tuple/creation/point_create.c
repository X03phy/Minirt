/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:41:31 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/01 14:01:36 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	point_create(double x, double y, double z)
{
	return (tuple_create(x, y, z, 1));
}
