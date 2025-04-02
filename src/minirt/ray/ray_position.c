/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:16:38 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 14:08:18 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

t_tuple	ray_position(t_ray r, double distance)
{
	return (
		add_tuples(r.origin, mul_tuple(r.direction, distance))
	);
}
