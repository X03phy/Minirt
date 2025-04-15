/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:15:05 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/14 12:35:40 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

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

void	print_cone(t_cone *c)
{
	printf(UBLU"CONE = \n"RESET);
	printf(BHBLU"ID : %d \n"RESET, c->id);
	printf("Summit : \n\t");
	tuple_print(&c->summit);
	printf("Orientation : \n\t");
	tuple_print(&c->orientation_vec);
	printf("\tAngle : %f Height : %f\nColor : ", c->angle, c->height);
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
		else if (((t_object_node *)obj->content)->type == CONE)
			print_cone(((t_object_node *)obj->content)->obj);
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
