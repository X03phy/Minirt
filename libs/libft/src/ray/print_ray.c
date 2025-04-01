/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:12:29 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:14:04 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	print_ray(t_ray r)
{
	printf("RAY:\norigin = ");
	print_tuples(&r.origin);
	printf("direction = ");
	print_tuples(&r.direction);
}
