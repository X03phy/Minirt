/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:29:53 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/18 22:50:18 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/ray.h"

t_intersection	*test_ray_for_pixel(t_config *c, int x, int y)
{
	c->render.world_y = c->render.half - (y * c->render.pixel_size);
	c->render.world_x = -c->render.half + (x * c->render.pixel_size);
	c->render.pixel_offset = tuple_add(
			tuple_add(
				tuple_multiply(c->render.right, c->render.world_x),
				tuple_multiply(c->render.up, c->render.world_y)
				),
			tuple_multiply(c->render.forward, c->render.dist_cam_wall));
	c->render.pixel_world = tuple_add(c->camera->position,
			c->render.pixel_offset);
	c->render.dir = vector_normalize(tuple_substitute(
				c->render.pixel_world, c->camera->position));
	c->render.ray = ray_create(c->camera->position, c->render.dir);
	return (hit(c, c->render.ray, NULL));

}

void	print_obj_infos(t_intersection *xs)
{
	if (!xs)
		return ;
	printf("Intersected object infos :\n");
	if (xs->object->type == SPHERE)
		print_sphere(xs->object->obj);
	else if (xs->object->type == PLANE)
		print_plane(xs->object->obj);
	else if (xs->object->type == DISK)
		print_disk(xs->object->obj);
	else if (xs->object->type == CYLINDER)
		print_cylinder(xs->object->obj);
	else if (xs->object->type == CONE)
		print_cone(xs->object->obj);
}

void	simulate_render(t_config *c, t_intersection *xs)
{
	c->render.x_point = ray_position(c->render.ray, xs->t);
	if (xs->object->type == SPHERE)
		render_sphere(c, xs, &c->render);
	else if (xs->object->type == PLANE)
		render_plane(c, xs, &c->render);
	else if (xs->object->type == CYLINDER)
		render_cylinder(c, xs, &c->render);
	else if (xs->object->type == DISK)
		render_disk(c, xs, &c->render);
	else if (xs->object->type == CONE)
		render_cone(c, xs, &c->render);
	printf(YEL"Intersection point : "RESET);
	tuple_print(&c->render.x_point);
	printf(BLU"Normal vec : "RESET);
	tuple_print(&c->l.normal_vec);
}

void	gen_ray(t_config *c, int x, int y, bool printinfos)
{
	t_intersection	*xs;

	xs = test_ray_for_pixel(c, x, y);
	if (xs)
	{
		printf(GRN"Intersection found for pixel at %d:%d.\n"RESET, x, y);
		// if (printinfos)
		// 	print_obj_infos(xs);
		simulate_render(c, xs);
		free(xs);
	}
	else
		printf("Nothing.\n");
	(void)printinfos;
}
