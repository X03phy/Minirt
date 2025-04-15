/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:09:50 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/14 13:34:23 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../libs/libft/include/libft.h"
# include "minirt.h"
# include "objects.h"

void			ray_print(t_ray r);
t_ray			ray_create(t_tuple origin, t_tuple direction);
t_tuple			ray_position(t_ray r, double distance);
bool			ray_sphere_intersection(t_sphere *s, t_ray r, double *x);
bool			ray_plane_intersection(t_plane *p, t_ray r, double *x);
bool			ray_disk_intersection(t_disk *d, t_ray r, double *x);
t_ray			ray_transform(t_ray r, t_matrix *m);
t_intersection	*hit(t_config	*c, t_ray r, t_multi *thdata);
bool			ray_cylinder_intersection(t_cylinder *cylinder,
					t_ray ray, double *x);
bool			ray_cone_intersection(t_cone *c, t_ray r, double *x);

#endif
