/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:21:32 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:15:55 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*scaling_matrix(double x, double y, double z)
{
	t_matrice	*res;
	res = get_identity_matrix();
	if (!res)
		return (NULL);
	res->matrice[0][0] = x;
	res->matrice[1][1] = y;
	res->matrice[2][2] = z;
	return (res);
}
