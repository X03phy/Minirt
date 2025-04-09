/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:15:05 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/08 15:34:33 by ebonutto         ###   ########.fr       */
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

void	print_cylinder(t_cylinder *c)
{
	printf(UBLU"CYLINDER = \n"RESET);
	printf(BHBLU"ID : %d \n"RESET, c->id);
	printf("Center : \n\t");
	tuple_print(&c->center);
	printf("Orientation : \n\t");
	tuple_print(&c->orientation_vec);
	printf("\tDiameter : %f Height : %f\nColor : ", c->diameter, c->height);
	tuple_print(&c->color);

}

void	print_disk(t_disk *p)
{
	printf(UCYN"DISK = \n"RESET);
	printf(BHCYN"ID : %d \n"RESET, p->id);
	printf("Center : \n\t");
	tuple_print(&p->center);
	printf("Orientation : \n\t");
	tuple_print(&p->orientation_vec);
	printf("\tRadius : %f\n", p->radius);
	printf("\tColor :");
	tuple_print(&p->color);
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
		else if (((t_object_node *)obj->content)->type == DISK)
			print_disk(((t_object_node *)obj->content)->obj);
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
