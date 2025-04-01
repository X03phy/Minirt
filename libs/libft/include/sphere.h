/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:45:56 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:30 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "tuples.h"

typedef struct s_sphere
{
	t_tuple	center;
	double	radius;
}	t_sphere;
#endif
