/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:48 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 15:28:29 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"

t_matrice	*inversion_matrix(t_matrice *m)
{
	t_matrice	*result;

	if (!m)
		return (NULL);
	if (det_matrix(m) == 0)
		return (NULL);
	result = new_matrix(m->row, m->col, NULL);




	return (result);
}
