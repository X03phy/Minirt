/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:52:29 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 17:20:25 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/tuple.h"

t_tuple normal_at(t_tuple p1, t_tuple p2)
{
	return (normalize_tuple(sub_tuples(p2, p1)));
}
