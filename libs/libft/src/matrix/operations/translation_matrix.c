/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:50 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:15:12 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*translation_matrix(double x, double y, double z)
{
	t_matrice	*res;

	res = get_identity_matrix();
	if (!res)
		return (NULL);
	res->matrice[0][3] = x;
	res->matrice[1][3] = y;
	res->matrice[2][3] = z;
	return (res);
}
