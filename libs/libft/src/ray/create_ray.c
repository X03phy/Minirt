/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:01 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 18:39:41 by ebonutto         ###   ########.fr       */
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
