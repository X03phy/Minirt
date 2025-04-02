/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:26:46 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:43:27 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_rotate_x(double rad)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[1][1] = cos(rad);
	res->matrix[1][2] = -sin(rad);
	res->matrix[2][1] = sin(rad);
	res->matrix[2][2] = cos(rad);
	return (res);
}

t_matrix	*matrix_rotate_y(double rad)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[0][0] = cos(rad);
	res->matrix[0][2] = sin(rad);
	res->matrix[2][0] = -sin(rad);
	res->matrix[2][2] = cos(rad);
	return (res);
}

t_matrix	*matrix_rotate_z(double rad)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[0][0] = cos(rad);
	res->matrix[0][1] = -sin(rad);
	res->matrix[1][0] = sin(rad);
	res->matrix[1][1] = cos(rad);
	return (res);
}
