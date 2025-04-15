/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:14:15 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/10 10:16:05 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	print_ambient(t_ambient_light *a)
{
	printf(GRN"Ambient lighting = \n"RESET);
	printf("\tRatio : %f \nColor : ", a->ratio);
	tuple_print(&a->color);
}

void	print_camera(t_camera *c)
{
	if (!c)
		return ;
	printf(BLU"Camera = \n"RESET);
	printf("Position : \n\t");
	tuple_print(&c->position);
	printf("Orientation : \n\t");
	tuple_print(&c->orientation_vec);
	printf("\tFov : %d\n", c->fov);
}

void	print_light(t_light *l)
{
	if (!l)
		return ;
	printf(MAG"Light = \n"RESET);
	printf("Position : \n\t");
	tuple_print(&l->position);
	printf("\tBrightness : %f\n", l->brightness);
	printf("\tColor : ");
	tuple_print(&l->color);
}

void	print_plane(t_plane *p)
{
	printf(UCYN"PLANE = \n"RESET);
	printf(BHCYN"ID : %d \n"RESET, p->id);
	printf("Center : \n\t");
	tuple_print(&p->center);
	printf("Orientation : \n\t");
	tuple_print(&p->orientation_vec);
	printf("\tColor :");
	tuple_print(&p->color);
}

void	print_sphere(t_sphere *s)
{
	printf(UYEL"SPHERE = \n"RESET);
	printf(BHYEL"ID : %d \n"RESET, s->id);
	printf("Center : \n\t");
	tuple_print(&s->center);
	printf("\tRadius : %f\n\tColor : ", s->radius);
	tuple_print(&s->color);
}
