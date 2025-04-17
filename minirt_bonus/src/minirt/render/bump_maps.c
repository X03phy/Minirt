/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:56:14 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/17 17:17:45 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

t_tuple get_bump_color_sphere(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n)
{
    // Coordonnées UV à partir de la normale (mappage sphérique)
    float x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
    float y = 0.5 - asin(n->y) / M_PI;
    
    // Correction pour éviter les effets de bord
    x = fmod(x, 1.0);
    if (x < 0) x += 1.0;
    y = fmod(y, 1.0);
    if (y < 0) y += 1.0;
    
    // Calculer les coordonnées de pixel
    int u = (int)(x * (s->bump.imgw - 1));
    int v = (int)(y * (s->bump.imgh - 1));
    
    // Échantillonnage pour la dérivée en u
    int u_next = (u + 1) % s->bump.imgw;
    int color = mlx_get_color(&s->bump, u, v);
    int color_u = mlx_get_color(&s->bump, u_next, v);
    
    // Échantillonnage pour la dérivée en v
    int v_next = (v + 1) % s->bump.imgh;
    int color_v = mlx_get_color(&s->bump, u, v_next);
    
    // Calculer la luminosité (ou utiliser uniquement un canal comme hauteur)
    float height = (((color >> 16) & 0xFF) + ((color >> 8) & 0xFF) + (color & 0xFF)) / (3.0 * 255.0);
    float height_u = (((color_u >> 16) & 0xFF) + ((color_u >> 8) & 0xFF) + (color_u & 0xFF)) / (3.0 * 255.0);
    float height_v = (((color_v >> 16) & 0xFF) + ((color_v >> 8) & 0xFF) + (color_v & 0xFF)) / (3.0 * 255.0);
    
    // Facteur d'intensité de la bump map
    float bump_strength = 0.1; // Ajustez selon vos besoins
    
    // Calculer les dérivées (la pente)
    float du_height = (height_u - height) * bump_strength;
    float dv_height = (height_v - height) * bump_strength;
    
    // Calculer l'espace tangent
    float theta = atan2(n->z, n->x);
    // float phi = asin(n->y);
    
    t_tuple tangent = vector_normalize(tuple_create(-sin(theta), 0, cos(theta), 0));
    t_tuple bitangent = vector_normalize(vector_cross_product(*n, tangent));
    
    // Perturber la normale en fonction des dérivées
    t_tuple bumped_normal = *n;
    bumped_normal = tuple_substitute(
        bumped_normal,
        tuple_multiply(tangent, du_height)
    );
    bumped_normal = tuple_substitute(
        bumped_normal,
        tuple_multiply(bitangent, dv_height)
    );
    
    return vector_normalize(bumped_normal);
    
    (void)x_point;
    (void)c;
}
