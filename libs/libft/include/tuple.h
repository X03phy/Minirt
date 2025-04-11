/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:46:23 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/06 11:43:48 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <stdlib.h>
# include "memory.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>

# define POINT 1
# define VEC 0
# define EPSILON 0.00001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tuple;

// Creation
t_tuple	point_create(double x, double y, double z);
t_tuple	tuple_create(double x, double y, double z, int w);
t_tuple	tuple_negate(t_tuple a);
t_tuple	*tuple_new(double x, double y, double z, int w);
t_tuple	vector_create(double x, double y, double z);

// Operations
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_divide(t_tuple a, double factor);
t_tuple	tuple_multiply(t_tuple a, double factor);
t_tuple	tuple_mult_tuple(t_tuple a, t_tuple b);
t_tuple	tuple_substitute(t_tuple a, t_tuple b);
t_tuple	vector_cross_product(t_tuple a, t_tuple b);
double	vector_dot(t_tuple a, t_tuple b);
double	vector_magnitude(t_tuple a);
t_tuple	vector_normalize(t_tuple a);
t_tuple	vector_normal_at(t_tuple p1, t_tuple p2);
t_tuple	vector_reflect(t_tuple in, t_tuple normal);

// Utils
bool	tuple_equal(double a, double b);
void	tuple_print(t_tuple *tuple);

#endif
