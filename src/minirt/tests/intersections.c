/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:01:46 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/02 12:08:34 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/objects.h"
#include "../../../libs/minilibx-linux/mlx.h"

void	intersections()
{

}

void	test_intersections(void)
{
	t_sphere	s;
	t_intersection i1 = {1, &s};
	t_intersection i2 = {2, &s};
	t_intersection *xs = intersections();
}
