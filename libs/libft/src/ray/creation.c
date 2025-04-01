/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:01 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:12:20 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return r;
}
