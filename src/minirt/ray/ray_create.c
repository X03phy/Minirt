/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:01 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 14:51:03 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

t_ray	ray_create(t_tuple origin, t_tuple direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return r;
}
