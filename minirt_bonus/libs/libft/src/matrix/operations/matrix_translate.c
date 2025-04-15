/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:50 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:33:42 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_translate(double x, double y, double z)
{
	t_matrix	*res;

	res = matrix_identity();
	if (!res)
		return (NULL);
	res->matrix[0][3] = x;
	res->matrix[1][3] = y;
	res->matrix[2][3] = z;
	return (res);
}
