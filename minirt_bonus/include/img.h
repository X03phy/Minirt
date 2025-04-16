/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:40:44 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/16 17:08:03 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_len;
	int		endian;
	int		imgw;
	int		imgh;
}	t_img;
#endif
