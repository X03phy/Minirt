/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:23 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/04 11:47:37 by ebonutto         ###   ########.fr       */
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
t_tuple	point_create(double x, double y, double z);
t_tuple	tuple_create(double x, double y, double z, int w);
t_tuple	tuple_negate(t_tuple a);
t_tuple	*tuple_new(double x, double y, double z, int w);
t_tuple	vector_create(double x, double y, double z);

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

// Utils
bool	tuple_equal(double a, double b);
void	tuple_print(t_tuple *tuple);

#endif
