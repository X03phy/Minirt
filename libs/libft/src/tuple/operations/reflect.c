/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:44:02 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 17:50:56 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (sub_tuples(in, mul_tuple(normal, dot_tuples(in, normal) * 2)));
}
