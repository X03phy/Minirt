/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:50:19 by ebonutto          #+#    #+#             */
/*   Updated: 2025/04/17 11:49:14 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"
#include <math.h>

// void	dark_color(t_img *img, int x, int y)
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	color_at_px;
//
// 	color_at_px = get_color_at_pixel(img, x, y);
// 	r = color_at_px >> 16 & 0xFF;
// 	g = color_at_px >> 8 & 0xFF;
// 	b = color_at_px & 0xFF;
// 	my_mlx_pixel_put(img, x, y, create_trgb(0xFF, r / 2, g / 2, b / 2));
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	handle_colors(int c1, int c2)
{
	t_color	color1;
	t_color	color2;

	color1 = tuple_create(
		c1 >> 16 & 0xFF,
		c1 >> 8 & 0xFF,
		c1 & 0xFF,
		0
	);	
	color2 = tuple_create(
		c2 >> 16 & 0xFF,
		c2 >> 8 & 0xFF,
		c2 & 0xFF,
		0
	);

	return (color_to_int(tuple_mult_tuple(color1, color2)));
}

int	get_texture_color_sphere(t_config *c, t_sphere *s, t_tuple *x_point, t_tuple *n)
{
	float x = 0.5 + atan2(n->z, n->x) / (2 * M_PI);
	float y = 0.5 - asin(n->y) / M_PI;
	float u = x * s->texture.imgw + (s->texture.imgw / 4.0);
	float v = y * s->texture.imgh;
	int	colortexture = mlx_get_color(&s->texture, u, v);
	// int	bumpedtexture = 0;
	//
	// if (s->bump_name)
	// {
	// 	bumpedtexture = mlx_get_color(&s->bump, u, v);
	// 	return (handle_colors(colortexture, bumpedtexture));
	// }
	return (colortexture);
	(void)x_point;
	(void)s;
	(void)c;
}

int	get_texture_color_plane(t_config *c, t_plane *p, t_tuple *x_point, t_tuple *n)
{
   (void)p;
   (void)x_point;
   (void)n;
   (void)c;
   float u = x_point->x - floor(x_point->x);
   float v = x_point->z - floor(x_point->z);
   int tex_u = u * p->texture.imgw;
   int tex_v = v * p->texture.imgh;
   return ((int)mlx_get_color(&p->texture, tex_u, tex_v));
}

// int	get_texture_color_plane(t_config *c, t_plane *p, t_tuple *x_point, t_tuple *n)
// {
// 	int u, v;
//
// 	if (fabs(n->x) >= fabs(n->y) && fabs(n->x) >= fabs(n->z))
// 	{
// 		u = (int)x_point->y - floor(x_point->y);
// 		v = (int)x_point->z - floor(x_point->z);
// 	}
// 	else if (fabs(n->y) > fabs(n->z))
// 	{
// 		u = (int)x_point->x - floor(x_point->x);
// 		v = (int)x_point->z - floor(x_point->z);
// 	}
// 	else
// 	{
// 		u = (int)x_point->x - floor(x_point->x);
// 		v = (int)x_point->y - floor(x_point->y);
// 	}
// 	int tex_u = u * p->texture.imgw;
// 	int tex_v = v * p->texture.imgh;
// 	return ((int)mlx_get_color(&p->texture, tex_u, tex_v));
// 	(void)c;
// }
