/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:22:15 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:32:39 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrix	*matrix_identity(void)
{
	t_matrix	*result;

	result = matrix_new(4, 4, NULL);
	if (!result)
		return (NULL);
	result->matrix[0][0] = 1.0;
	result->matrix[1][1] = 1.0;
	result->matrix[2][2] = 1.0;
	result->matrix[3][3] = 1.0;
	return (result);
}
