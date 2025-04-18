/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:56:14 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/18 14:29:10 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

t_tuple get_rev_vector(t_tuple *n)
{
    if (fabs(n->y) < 0.9)
        return (vector_create(0, 1, 0));
    return (vector_create(0, 0, 1));
}

t_tuple get_bump_color_sphere(t_config *config, t_sphere *s, t_tuple *x_point, t_tuple *n, t_tuple *c)
{
    (void)s;
    (void)x_point;
    (void)config;

    t_tuple rev_vec = get_rev_vector(n);
    
    t_tuple t = vector_normalize(vector_cross_product(rev_vec, *n));
    t_tuple b =  vector_normalize(vector_cross_product(*n, t));
    // et on a deja n donc hassoul
    
    t_tuple new_normal = vector_create(0, 0, 0);
    new_normal.x = t.x * c->x + b.x * c->y + n->x * c->z;
    new_normal.y = t.y * c->x + b.y * c->y + n->y * c->z;
    new_normal.z = t.z * c->x + b.z * c->y + n->z * c->z;
    return (vector_normalize(new_normal));
}

int	get_bump_normal_sphere(t_config *c, t_sphere *s,
	t_tuple *x_point, t_tuple *n)
{
	float	x;
	float	y;
	float	u;
	float	v;
	int		colorbump;

	x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	y = 0.5 - asin(n->y) / M_PI;
	u = x * s->bump.imgw + (s->bump.imgw / 4.0);
	v = y * s->bump.imgh;
	colorbump = mlx_get_color(&s->bump, u, v);
	return (colorbump);
	(void)x_point;
	(void)s;
	(void)c;
}

// tangent space to world: n, normal dans la teture,

// tangent = vec_cross(rev_vec, normal);
// bitan = cross(normal, tangent);
// on a normal

// new_normal = [tan bitan normal] dot normal in txture
