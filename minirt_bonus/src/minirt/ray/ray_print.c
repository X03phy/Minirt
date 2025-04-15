/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:12:29 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/03 12:05:22 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

void	ray_print(t_ray r)
{
	printf("RAY:\norigin = ");
	tuple_print(&r.origin);
	printf("direction = ");
	tuple_print(&r.direction);
}
