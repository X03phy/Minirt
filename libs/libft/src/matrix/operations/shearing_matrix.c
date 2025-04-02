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

t_matrix	*matrix_shear(double xy , double xz , double yx , double yz , double zx , double zy)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[0][1] = xy;
	res->matrix[0][2] = xz;
	res->matrix[1][0] = yx;
	res->matrix[1][2] = yz;
	res->matrix[2][0] = zx;
	res->matrix[2][1] = zy;
	return (res);
}
