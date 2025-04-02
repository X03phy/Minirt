/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:19:40 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 14:09:46 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

t_ray	ray_transform(t_ray r, t_matrix *m)
{
	t_ray	new_ray;

	new_ray.origin = matrix_multiply_tuple(m, r.origin);
	new_ray.direction = matrix_multiply_tuple(m, r.direction);
	return (new_ray);
}
