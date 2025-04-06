/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:30:34 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/06 12:32:48 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

// vieu
// t_color	lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv, t_config *c)
// {
// 	t_tuple	effective_color = tuple_multiply(m.color, l.brightness);
// 	
// 	t_tuple	lightv = vector_normalize(tuple_substitute(l.position, p));
//
// 	t_tuple ambient = tuple_multiply(effective_color, m.ambient);
//
// 	double	light_dot_normal = vector_dot(lightv, normalv);
// 	
// 	t_color	diffuse = point_create(0, 0, 0);
// 	t_color	specular = point_create(0, 0, 0);
// 	if (light_dot_normal >= 0) 
// 	{
// 		diffuse = tuple_multiply(effective_color, m.diffuse * light_dot_normal);
// 		t_tuple	reflectv = vector_reflect(tuple_negate(lightv), normalv);
// 		double tuple_multiply_dot_eye = vector_dot(reflectv, eyev);
// 		if (tuple_multiply_dot_eye > 0)
// 		{
// 			double factor = pow(tuple_multiply_dot_eye, m.shininess);
// 			t_color	white = point_create(1, 1, 1);
// 			specular = tuple_multiply(white, m.specular * factor);
// 		}
// 	}
// 	return (tuple_add(tuple_add(ambient, diffuse), specular));
// 	(void)c;
// }

// t_color lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv, t_config *c)
// {
// 	t_tuple	effective_color = tuple_multiply(m.color, l.brightness);
//     t_tuple lightv = vector_normalize(tuple_substitute(l.position, p));
//
//     t_color ambient = tuple_multiply(tuple_add(effective_color, tuple_mult_tuple(m.color, tuple_multiply(c->ambient_light->color, c->ambient_light->ratio))), m.ambient);
//
//     double light_dot_normal = vector_dot(lightv, normalv);
//
//     t_color diffuse = point_create(0, 0, 0);
//     t_color specular = point_create(0, 0, 0);
//     if (light_dot_normal >= 0)
//     {
//         // Diffuse : interaction par multiplication
//         diffuse = tuple_multiply(tuple_add(tuple_mult_tuple(m.color, l.color), effective_color), m.diffuse * light_dot_normal);
//
//         // Calcul du vecteur de réflexion
//         t_tuple reflectv = vector_reflect(tuple_negate(lightv), normalv);
//         double reflect_dot_eye = vector_dot(reflectv, eyev);
//         if (reflect_dot_eye > 0)
//         {
//             double factor = pow(reflect_dot_eye, m.shininess);
//             specular = tuple_multiply(tuple_add(l.color, effective_color), m.specular * factor);
//         }
//     }
//     return tuple_add(tuple_add(ambient, diffuse), specular);
// }

t_color lighting(t_material m, t_light l, t_tuple p, t_tuple eyev, t_tuple normalv, t_config *c)
{
    // Couleur effective : ici on peut ne pas inclure l.brightness, ou l'utiliser uniquement dans la diffuse et spéculaire
    // t_color effective_color = m.color; // ou tuple_multiply(m.color, l.brightness) selon ton pipeline

    // Vecteur de la lumière
    t_tuple lightv = vector_normalize(tuple_substitute(l.position, p));

    // Contribution ambiante : produit par canal
    t_color ambient = tuple_mult_tuple(m.color, tuple_multiply(c->ambient_light->color, c->ambient_light->ratio));
    ambient = tuple_multiply(ambient, m.ambient);

    double light_dot_normal = vector_dot(lightv, normalv);

    t_color diffuse = point_create(0, 0, 0);
    t_color specular = point_create(0, 0, 0);
    if (light_dot_normal >= 0)
    {
        t_color diffuse_color = tuple_add(m.color, l.color);
        diffuse = tuple_multiply(diffuse_color, m.diffuse * light_dot_normal);

        // Calcul du vecteur de réflexion
        t_tuple reflectv = vector_reflect(tuple_negate(lightv), normalv);
        double reflect_dot_eye = vector_dot(reflectv, eyev);
        if (reflect_dot_eye > 0)
        {
            double factor = pow(reflect_dot_eye, m.shininess);
            // Specular : généralement teinté par la lumière (ou blanc si on veut)
            specular = tuple_multiply(l.color, m.specular * factor);
        }
    }
    return tuple_add(tuple_add(ambient, diffuse), specular);
}
