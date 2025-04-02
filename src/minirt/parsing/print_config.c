/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:15:05 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 15:53:42 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

void	print_ambient(t_ambient_light *a)
{
	printf(GRN"Ambient lighting = \n"RESET);
	printf("\tRatio : %f Color: 0x%X\n", a->ratio, a->color);
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
	printf("\tColor : 0x%X\n", l->color);
}

void	print_plane(t_plane *p)
{
	printf(CYN"PLANE = \n"RESET);
	printf("Center : \n\t");
	print_tuple(&p->center);
	printf("Orientation : \n\t");
	print_tuple(&p->orientation_vec);
	printf("\tColor : 0x%X\n", p->color);
}

void	print_sphere(t_sphere *s)
{
	printf(YEL"SPHERE = \n"RESET);
	printf("Center : \n\t");
	print_tuple(&s->center);
	printf("\tRadius : %f\n\tColor : 0x%X\n", s->radius, s->color);
}

void	print_cylinder(t_cylinder *c)
{
	printf(BLUB"CYLINDER = \n"RESET);
	printf("Center : \n\t");
	print_tuple(&c->center);
	printf("Orientation : \n\t");
	print_tuple(&c->orientation_vec);
	printf("\tDiameter : %f Height : %f Color : 0x%X\n", c->diameter, c->diameter, c->color);

}

void	print_objects(t_list *obj)
{
	while (obj)
	{
		if (((t_object_node *)obj->content)->type == PLANE)
			print_plane(obj->content);
		else if (((t_object_node *)obj->content)->type == SPHERE)
			print_sphere(obj->content);
		else if (((t_object_node *)obj->content)->type == CYLINDER)
			print_cylinder(obj->content);
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
