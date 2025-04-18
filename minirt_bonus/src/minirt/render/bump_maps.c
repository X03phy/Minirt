/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:56:14 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/18 13:42:41 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

t_tuple get_rev_vector(t_tuple *n)
{
    if (fabs(n->y) < 0.9)
        return (vector_create(0, 1, 0));
    else
        return (vector_create(1, 0, 0));
}

t_tuple get_bump_color_sphere(t_config *config, t_sphere *s, t_tuple *x_point, t_tuple *n, t_tuple *c)
{
    (void)s;
    (void)x_point;

    (void)config;
    t_tuple rev_vec = get_rev_vector(n);
    
    t_tuple t = vector_cross_product(rev_vec, *n);
    t_tuple b = vector_cross_product(*n, t);
    // et on a deja n donc hassoul
    
    t_tuple new_normal = vector_create(0, 0, 0);
    new_normal.x = t.x * c->x + b.x * c->y + n->x * c->z;
    new_normal.y = t.y * c->x + b.y * c->y + n->y * c->z;
    new_normal.z = t.z * c->x + b.z * c->y + n->z * c->z;
    return (new_normal);
}

// tangent space to world: n, normal dans la teture,

// tangent = vec_cross(rev_vec, normal);
// bitan = cross(normal, tangent);
// on a normal

// new_normal = [tan bitan normal] dot normal in txture
