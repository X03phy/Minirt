/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:07:22 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 11:07:46 by maecarva         ###   ########.fr       */
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
	t_matrix	*transpose;

	inv = matrix_inverse(transform);
	object_point = matrix_multiply_tuple(inv, world_point);
	object_normal = tuple_substitute(object_point, p1);
	transpose = matrix_transpose(inv);
	world_normal = matrix_multiply_tuple(transpose, object_normal);
	world_normal.w = 0;
	matrix_free(&inv);
	matrix_free(&transpose);
	return (vector_normalize(world_normal));
}
