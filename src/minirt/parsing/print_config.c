/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:15:05 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 19:06:29 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	print_ambient(t_ambient_light *a)
{
	printf(GRN"Ambient lighting = \n"RESET);
	printf("\tRatio : %f \nColor : ", a->ratio);
	print_tuple(&a->color);
}

void	print_camera(t_camera *c)
{
	if (!c)
		return ;
	printf(BLU"Camera = \n"RESET);
	printf("Position : \n\t");
	print_tuple(&c->position);
	printf("Orientation : \n\t");
	print_tuple(&c->orientation_vec);
	printf("\tFov : %d\n", c->fov);
}

void	print_light(t_light *l)
{
	if (!l)
		return ;
	printf(MAG"Light = \n"RESET);
	printf("Position : \n\t");
	print_tuple(&l->position);
	printf("\tBrightness : %f\n", l->brightness);
	printf("\tColor : ");
	print_tuple(&l->color);
}

void	print_plane(t_plane *p)
{
	printf(UCYN"PLANE = \n"RESET);
	printf(BHCYN"ID : %d \n"RESET, p->id);
	printf("Center : \n\t");
	print_tuple(&p->center);
	printf("Orientation : \n\t");
	print_tuple(&p->orientation_vec);
	printf("\tColor :");
	print_tuple(&p->color);
}

void	print_sphere(t_sphere *s)
{
	printf(UYEL"SPHERE = \n"RESET);
	printf(BHYEL"ID : %d \n"RESET, s->id);
	printf("Center : \n\t");
	print_tuple(&s->center);
	printf("\tRadius : %f\n\tColor : ", s->radius);
	print_tuple(&s->color);
}

void	print_cylinder(t_cylinder *c)
{
	printf(UBLU"CYLINDER = \n"RESET);
	printf(BHBLU"ID : %d \n"RESET, c->id);
	printf("Center : \n\t");
	print_tuple(&c->center);
	printf("Orientation : \n\t");
	print_tuple(&c->orientation_vec);
	printf("\tDiameter : %f Height : %f\nColor : ", c->diameter, c->height);
	print_tuple(&c->color);

}

void	print_objects(t_list *obj)
{
	while (obj)
	{
		if (((t_object_node *)obj->content)->type == PLANE)
			print_plane(((t_object_node *)obj->content)->obj);
		else if (((t_object_node *)obj->content)->type == SPHERE)
			print_sphere(((t_object_node *)obj->content)->obj);
		else if (((t_object_node *)obj->content)->type == CYLINDER)
			print_cylinder(((t_object_node *)obj->content)->obj);
		else
			printf(RED"WRONG obj type.\n"RESET);
		obj = obj->next;
	}
}

void	print_config(t_config *c)
{
	if (!c)
		return ;
	print_ambient(c->ambient_light);
	print_camera(c->camera);
	print_light(c->light);
	print_objects(c->objects_list);
}
