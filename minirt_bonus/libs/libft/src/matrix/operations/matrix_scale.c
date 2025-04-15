/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:21:32 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/11 11:01:57 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_scale(double x, double y, double z)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[0][0] = x;
	res->matrix[1][1] = y;
	res->matrix[2][2] = z;
	return (res);
}
