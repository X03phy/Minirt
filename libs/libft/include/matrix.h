/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:06:06 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 17:16:45 by ebonutto         ###   ########.fr       */
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

typedef struct s_matrice
{
	int		col;
	int		row;
	double	**matrice;
}	t_matrice;

// Creation
t_matrice	*new_matrix(int row, int col, double *value);

// Operations
double		cofactor_matrix(t_matrice *m, int row, int col);
double		det_matrix(t_matrice *m);
t_matrice	*get_identity_matrix(void);
t_matrice	*inversion_matrix(t_matrice *m);
double		minor_matrix(t_matrice *m, int row, int col);
t_matrice	*mul_matrices(t_matrice *m1, t_matrice *m2);
t_tuple		mul_matrix_tuple(t_matrice *m, t_tuple t);
t_matrice	*submatrix(t_matrice *m, int row, int col);
t_matrice	*transpose_matrix(t_matrice	*m);
t_matrice	*translation_matrix(double x, double y, double z);
t_matrice	*scaling_matrix(double x, double y, double z);
t_matrice	*rotate_x(double rad);
t_matrice	*rotate_y(double rad);
t_matrice	*rotate_z(double rad);
t_matrice	*shearing_matrix(double xy , double xz , double yx , double yz , double zx , double zy);

// Utils
t_matrice	*clean_matrix(t_matrice **m);
void		print_matrix(t_matrice *m);
bool		equal_matrices(t_matrice *m1, t_matrice *m2);

#endif // !MATRIX_H
