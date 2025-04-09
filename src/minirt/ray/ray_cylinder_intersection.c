/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:29:52 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/08 13:33:19 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

bool	ray_cylinder_intersection2(t_cylinder *cylinder, t_ray ray, double *x)
{
	double	inter[2];
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = pow(ray.direction.x, 2.0) + pow(ray.direction.z, 2.0);
	if (a < EPSILON)
		return (false);
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2.0) + pow(ray.origin.z, 2.0) - (pow(cylinder->diameter / 2, 2));
	
	discriminant = pow(b, 2.0) - (4 * a * c);

	if (discriminant < 0)
		return (false);
	inter[0] = (-b - sqrt(discriminant)) / (2 * a);
	inter[1] = (-b + sqrt(discriminant)) / (2 * a);
	
	double y_intersection = ray.origin.y + (fmin(inter[0], inter[1])) * ray.direction.y;
	if (y_intersection < -1 * cylinder->height / 2 || y_intersection > cylinder->height / 2)
		return (false);  // L'intersection est en dehors de la hauteur du cylindre
	*x = fmin(inter[0], inter[1]);
	return (true);
}

bool ray_cylinder_intersection3(t_cylinder *cylinder, t_ray ray, double *x)
{
    double inter[2];
    double a, b, c_val;
    double discriminant;
    
    // Coordonnées relatives par rapport au centre du cylindre (pour x et z)
    double ox = ray.origin.x - cylinder->center.x;
    double oz = ray.origin.z - cylinder->center.z;
    
    a = pow(ray.direction.x, 2.0) + pow(ray.direction.z, 2.0);
    if (fabs(a) < EPSILON)
        return false;
    
    double r = cylinder->diameter / 2.0;
    b = 2 * (ox * ray.direction.x + oz * ray.direction.z);
    c_val = pow(ox, 2.0) + pow(oz, 2.0) - pow(r, 2);
    
    discriminant = pow(b, 2.0) - (4 * a * c_val);
    if (discriminant < 0)
        return false;
    
    inter[0] = (-b - sqrt(discriminant)) / (2 * a);
    inter[1] = (-b + sqrt(discriminant)) / (2 * a);
    
    // Choisir la solution la plus proche positive
    // double t_candidate = fmin(inter[0], inter[1]);
    // if (t_candidate < EPSILON)
    //     t_candidate = fmax(inter[0], inter[1]);
    // if (t_candidate < EPSILON)
    //     return false;
    
    // Calcul de la coordonnée Y de l'intersection
    double y_intersection = ray.origin.y + fmin(inter[0], inter[1]) * ray.direction.y;
    double min_y = cylinder->center.y - (cylinder->height / 2.0);
    double max_y = cylinder->center.y + (cylinder->height / 2.0);
    if (y_intersection < min_y || y_intersection > max_y)
        return false;  // L'intersection est en dehors de la hauteur du cylindre
    
    *x = fmin(inter[0], inter[1]);
    return true;
}

// bool ray_cylinder_intersection(t_cylinder *cylinder, t_ray ray, double *x)
// {
//     double inter[2];
//     double a, b, c;
//     double discriminant;
    
//     t_tuple X = tuple_substitute(ray.origin, cylinder->center);
//     double d_dot_v = vector_dot(ray.direction, cylinder->orientation_vec);
//     double x_dot_v = vector_dot(X, cylinder->orientation_vec);
    
//     a = 1 - pow(d_dot_v, 2.0);
//     if (fabs(a) < EPSILON)
//         return false;
    
//     b = 2.0 * (vector_dot(ray.direction, X) - d_dot_v * x_dot_v);

//     c = vector_dot(X, X) - pow(x_dot_v, 2.0) - pow((cylinder->diameter / 2), 2.0);
    
//     discriminant = pow(b, 2.0) - (4 * a * c);
//     if (discriminant < 0)
//         return false;
//     else if (discriminant < EPSILON)
//     {
//         inter[0] = (-b) / (2 * a);
//         inter[1] = inter[0];
//     }
//     else
//     {
//         double sqrt_disc = sqrt(discriminant);
//         inter[0] = (-b - sqrt_disc) / (2 * a);
//         inter[1] = (-b + sqrt_disc) / (2 * a);
//     }
//     // Choisir la solution la plus proche positive                  Je capte pas l utilite en vrai (enft si je crois avoir capte)
//     double t_candidate = fmax(inter[0], inter[1]); 
//     // double t_candidate = fmax(inter[0], inter[1]);            // inverse les deux cotes donc ligne importante
//                // inverse les deux cotes donc ligne importante
//     // if (t_candidate < EPSILON)
//     //     return false;
    
//     // Calcul du point d'intersection
//     t_tuple hit_point = tuple_add(ray.origin, tuple_multiply(ray.direction, t_candidate));  // Position d'intersection du rayon
    
//     // Projeter le point d'intersection sur l'axe d'orientation du cylindre
//     t_tuple from_center = tuple_substitute(hit_point, cylinder->center);
//     double projection = vector_dot(from_center, cylinder->orientation_vec);  // Projection sur l'axe du cylindre
    
//     // Vérifier si l'intersection est dans la hauteur du cylindre
//     if (projection < -cylinder->height / 2.0 || projection > cylinder->height / 2.0)
//         return false;  // L'intersection est en dehors de la hauteur du cylindre
    
//     *x = t_candidate;
//     return true;
// }

bool ray_cylinder_intersection(t_cylinder *cylinder, t_ray ray, double *x)
{
    double inter[2];
    double a, b, c;
    double discriminant;
    
    t_tuple X = tuple_substitute(ray.origin, cylinder->center);
    double d_dot_v = vector_dot(ray.direction, cylinder->orientation_vec);
    double x_dot_v = vector_dot(X, cylinder->orientation_vec);
    
    a = 1 - pow(d_dot_v, 2.0);
    if (fabs(a) < EPSILON)
        return false;
    
    b = 2.0 * (vector_dot(ray.direction, X) - d_dot_v * x_dot_v);

    c = vector_dot(X, X) - pow(x_dot_v, 2.0) - pow((cylinder->diameter / 2), 2.0);
    
    discriminant = pow(b, 2.0) - (4 * a * c);
    if (discriminant < 0)
        return false;
    else if (discriminant < EPSILON)
    {
        inter[0] = (-b) / (2 * a);
        inter[1] = inter[0];
    }
    else
    {
        double sqrt_disc = sqrt(discriminant);
        inter[0] = (-b - sqrt_disc) / (2 * a);
        inter[1] = (-b + sqrt_disc) / (2 * a);
    }
    // Choisir la solution la plus proche positive                  Je capte pas l utilite en vrai (enft si je crois avoir capte)
    double t_candidate = fmin(inter[0], inter[1]); 
    // double t_candidate = fmax(inter[0], inter[1]);            // inverse les deux cotes donc ligne importante
               // inverse les deux cotes donc ligne importante
    // if (t_candidate < EPSILON)
    //     return false;
    
    // Calcul du point d'intersection
    t_tuple hit_point = tuple_add(ray.origin, tuple_multiply(ray.direction, t_candidate));  // Position d'intersection du rayon
    
    // Projeter le point d'intersection sur l'axe d'orientation du cylindre
    t_tuple from_center = tuple_substitute(hit_point, cylinder->center);
    double projection = vector_dot(from_center, cylinder->orientation_vec);  // Projection sur l'axe du cylindre
    
    // Vérifier si l'intersection est dans la hauteur du cylindre
    if (projection < -cylinder->height / 2.0 || projection > cylinder->height / 2.0)
        return (false);
    *x = t_candidate;
    return true;
}
