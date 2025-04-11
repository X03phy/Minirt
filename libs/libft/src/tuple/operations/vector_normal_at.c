/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normal_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:52:29 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/11 11:09:49 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	vector_normal_at(t_tuple p1, t_tuple p2)
{
	return (vector_normalize(tuple_substitute(p2, p1)));
}
