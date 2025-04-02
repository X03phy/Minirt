/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:12:29 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:26:21 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ray_print(t_ray r)
{
	printf("RAY:\norigin = ");
	print_tuples(&r.origin);
	printf("direction = ");
	print_tuples(&r.direction);
}
