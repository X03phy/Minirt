/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:23 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 18:14:51 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

#include <stdlib.h>
#include "memory.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

# define POINT 1
# define VEC 0
# define EPSILON 0.00001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	int		w; // 0 == vec, 1 == point
}	t_tuple;

// Creation
t_tuple	new_neg_tuple(t_tuple a);
t_tuple	new_point(double x, double y, double z);
t_tuple	*new_tuple_ptr(double x, double y, double z, int w);
t_tuple	new_tuple(double x, double y, double z, int w);
t_tuple	new_vec(double x, double y, double z);

// Operations
t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	cross_tuples(t_tuple a, t_tuple b);
t_tuple	div_tuple(t_tuple a, double factor);
double	dot_tuples(t_tuple a, t_tuple b);
double	mag_tuple(t_tuple a);
t_tuple	mul_tuple(t_tuple a, double factor);
t_tuple	normalize_tuple(t_tuple a);
t_tuple	sub_tuples(t_tuple a, t_tuple b);
t_tuple normal_at(t_tuple p1, t_tuple p2);
t_tuple	reflect(t_tuple in, t_tuple normal);
t_tuple	normal_at_transform(void *transform, t_tuple p1, t_tuple world_point);

// Utils
bool	equal_tuples(double a, double b);
void	print_tuple(t_tuple *tuple);

#endif
