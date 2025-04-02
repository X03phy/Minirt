/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:09:50 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 09:40:16 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "tuple.h"
# include "sphere.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;



void	print_ray(t_ray r);
t_ray	create_ray(t_tuple origin, t_tuple direction);
t_tuple	ray_position(t_ray r, double distance);
double	*ray_sphere_intersection(t_sphere s, t_ray r);

#endif
