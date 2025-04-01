/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:26:46 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:07:57 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*rotate_x(double rad)
{
	t_matrice	*res;

	res = get_identity_matrix();
	if (!res)
		return (NULL);
	res->matrice[1][1] = cos(rad);
	res->matrice[1][2] = -sin(rad);
	res->matrice[2][1] = sin(rad);
	res->matrice[2][2] = cos(rad);
	return (res);
}

t_matrice	*rotate_y(double rad)
{
	t_matrice	*res;

	res = get_identity_matrix();
	if (!res)
		return (NULL);
	res->matrice[0][0] = cos(rad);
	res->matrice[0][2] = sin(rad);
	res->matrice[2][0] = -sin(rad);
	res->matrice[2][2] = cos(rad);
	return (res);
}

t_matrice	*rotate_z(double rad)
{
	t_matrice	*res;

	res = get_identity_matrix();
	if (!res)
		return (NULL);
	res->matrice[0][0] = cos(rad);
	res->matrice[0][1] = -sin(rad);
	res->matrice[1][0] = sin(rad);
	res->matrice[1][1] = cos(rad);
	return (res);
}
