/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:59:28 by maecarva          #+#    #+#             */
/*   Updated: 2025/03/31 16:32:17 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "../libs/libft/inc/libft.h"
# include "../libs/minilibx/mlx.h"
# include "keycodes.h"
# include "tuples.h"
# include "matrices.h"
# include "color.h"

# define EPSILON 0.00001
# define PI 3.145926

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_config
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}	t_config;

void	clean_exit(t_config *config);
void	install_hooks(t_config *config);

// tests
void	tuples_tests(void);
void	tuples_proj_test(void);

#endif
