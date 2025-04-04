/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_phong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:13:23 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/04 15:13:45 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include "../../../include/objects.h"
#include "../../../include/ray.h"
#include "../../../libs/minilibx-linux/mlx.h"

// double	get_sphere_hit(double	*intersections)
// {
// 	if (intersections[0] > intersections[1])
// 		return (intersections[1]);
// 	return (intersections[0]);
// }
//
// int	color_to_int(t_color color)
// {
// 	int	r;
// 	int	g;
// 	int	b;
//
// 	r = (fmin(fmax(color.x, 0.0), 1.0) * 255);
// 	g = (fmin(fmax(color.y, 0.0), 1.0) * 255);
// 	b = (fmin(fmax(color.z, 0.0), 1.0) * 255);
// 	return (
// 		(r << 16 | g << 8 | b)
// 	);
// }
//
// void	test_phong(t_config *c)
// {
// 	c->mlx = mlx_init();
// 	if (c->mlx == NULL)
// 		return ;
// 	c->mlx_win = mlx_new_window(c->mlx, 1000, 1000, "MiniRT");
// 		
// 	c->img.img = mlx_new_image(c->mlx, 1000, 1000);
// 	c->img.addr = mlx_get_data_addr(c->img.img,
// 			&c->img.bits_per_pixels,
// 			&c->img.line_len, &c->img.endian);
//
// 	t_tuple	ray_origin = point_create(0, 0, -5);
// 	int	wall_z = 10;
// 	double	wall_size = 7.0;
//
// 	double	image_pixels = 1000;
// 	double	pixel_size = wall_size / image_pixels;
// 	double	half = wall_size / 2;
//
// 	t_sphere *s = ((t_object_node *)c->objects_list->content)->obj;
//
// 	t_material m;
// 	m.ambient = 0.1;
//     m.diffuse = 0.9;
//     m.specular = 0.9;
//     m.shininess = 200.0;
//     m.color = s->color;
//     s->material = m;
//
// 	double *xs;
// 	for (int y = 0; y < image_pixels; y++)
// 	{
// 		double world_y = half - (y * pixel_size);
// 		for (int x = 0; x < image_pixels; x++)
// 		{
// 			double world_x = -half + (x * pixel_size);
// 			t_tuple	position = point_create(world_x, world_y, wall_z);
// 			t_ray	r = ray_create(ray_origin, vector_normalize(tuple_substitute(position, ray_origin)));
// 			xs = ray_sphere_intersection((t_sphere)*s, r, NULL);
// 			if (xs)
// 			{
// 				double	first_intersection = get_sphere_hit(xs);
// 				// point d-intersection sur la sphere
// 				t_tuple	x_point = ray_position(r, first_intersection);
// 				// vecteur normal a la sphere en ce point
// 				t_tuple	normal_vec = vector_normalize(tuple_substitute(x_point, s->center));
//
// 				// eye vector
// 				t_tuple	eyev = tuple_negate(r.direction);
//
// 				t_tuple	color = lighting(s->material, *c->light, x_point, eyev, normal_vec);
// 				int	colorint = color_to_int(color);
// 				// printf("Color : 0x%X\n", colorint);
// 				my_mlx_pixel_put(&c->img, x, y, colorint);
// 				free(xs);
// 			}
// 		}
// 	}
// 	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img.img, 0, 0);
// 	install_hooks(c);
// 	mlx_loop(c->mlx);
// }

