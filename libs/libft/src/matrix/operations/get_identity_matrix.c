/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identity_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:22:15 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:28:14 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*get_identity_matrix(void)
{
	t_matrice	*result;

	result = new_matrix(4, 4, NULL);
	if (!result)
		return (NULL);
	result->matrice[0][0] = 1.0;
	result->matrice[1][1] = 1.0;
	result->matrice[2][2] = 1.0;
	result->matrice[3][3] = 1.0;
	return (result);
}
