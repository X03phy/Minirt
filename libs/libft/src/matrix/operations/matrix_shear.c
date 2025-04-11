/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_shear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:21:12 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:33:42 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_shear(t_shear *shear)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[0][1] = shear->xy;
	res->matrix[0][2] = shear->xz;
	res->matrix[1][0] = shear->yx;
	res->matrix[1][2] = shear->yz;
	res->matrix[2][0] = shear->zx;
	res->matrix[2][1] = shear->zy;
	return (res);
}
