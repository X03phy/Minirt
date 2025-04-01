/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:21:12 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:24:03 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*shearing(double xy , double xz , double yx , double yz , double zx , double zy)
{
	t_matrice	*res;

	res = get_identity_matrix();
	if (!res)
		return (NULL);
	res->matrice[0][1] = xy;
	res->matrice[0][2] = xz;
	res->matrice[1][0] = yx;
	res->matrice[1][2] = yz;
	res->matrice[2][0] = zx;
	res->matrice[2][1] = zy;
	return (res);
}
