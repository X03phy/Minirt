/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:06:06 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 12:43:27 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "tuple.h"
#include "safe.h"

/*
*
| 1.000  | 2.000  | 3.000  | 4.000  |
| 5.500  | 6.500  | 7.500  | 8.500  |
| 9.000  | 10.000 | 11.000 | 12.000 |
| 13.500 | 14.500 | 15.500 | 16.500 |
 
 M[3,2] = 15.5
	descendre de 3 puis 2 vers la droite
* */

typedef struct s_matrix
{
	int		col;
	int		row;
	double	**matrix;
}	t_matrix;

// Creation
t_matrix	*matrix_new(int row, int col, double *value);

// Operations
double		matrix_cofactor(t_matrix *m, int row, int col);
double		matrix_determinant(t_matrix *m);
t_matrix	*matrix_identity(void);
t_matrix	*matrix_inverse(t_matrix *m);
double		matrix_minor(t_matrix *m, int row, int col);
t_matrix	*matrix_multiply(t_matrix *m1, t_matrix *m2);
t_tuple		matrix_multiply_tuple(t_matrix *m, t_tuple t);
t_matrix	*matrix_submatrix(t_matrix *m, int row, int col);
t_matrix	*matrix_transpose(t_matrix	*m);
t_matrix	*matrix_translate(double x, double y, double z);
t_matrix	*matrix_scale(double x, double y, double z);
t_matrix	*matrix_rotate_x(double rad);
t_matrix	*matrix_rotate_y(double rad);
t_matrix	*matrix_rotate_z(double rad);
t_matrix	*matrix_shear(double xy , double xz , double yx , double yz , double zx , double zy);

// Utils
t_matrix	*matrix_free(t_matrix **m);
void		matrix_print(t_matrix *m);
bool		matrix_equal(t_matrix *m1, t_matrix *m2);

#endif // !MATRIX_H
