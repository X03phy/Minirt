/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:07:22 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 18:15:37 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"
#include "../../../include/matrix.h"

t_tuple	normal_at_transform(void *transform, t_tuple p1, t_tuple world_point)
{
	t_matrix	*inv;
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;

	inv = matrix_inverse(transform);
	object_point = matrix_multiply_tuple(inv, world_point);
	object_normal = sub_tuples(object_point, p1);
	t_matrix *transpose = matrix_transpose(inv);
	world_normal = matrix_multiply_tuple(transpose, object_normal);
	world_normal.w = 0;
	matrix_free(&inv);
	matrix_free(&transpose);
	return (normalize_tuple(world_normal));
}
