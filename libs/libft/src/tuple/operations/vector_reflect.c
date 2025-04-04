/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:44:02 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/03 13:44:52 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple	vector_reflect(t_tuple in, t_tuple normal)
{
	return (tuple_substitute(in, tuple_multiply(normal, vector_dot(in, normal) * 2)));
}
