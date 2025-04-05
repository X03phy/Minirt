/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:29:52 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/05 16:00:05 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/objects.h"
#include "../../../include/minirt.h"
#include "../../../include/ray.h"
#include <math.h>

bool	ray_cylinder_intersection(t_cylinder *cylinder, t_ray ray, double *x)
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
	c = pow(ray.origin.x, 2.0) + pow(ray.origin.z, 2.0) - (cylinder->diameter / 2);
	
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
