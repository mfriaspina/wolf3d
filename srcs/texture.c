/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:00:20 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/11 14:32:39 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

/*
** This function returns the color value of the image given in a specific
** position.
*/

unsigned int	get_pixel_color(t_img *img, t_point a)
{
	int				i;
	unsigned int	color;

	color = 0;
	i = (a.x * img->bpp / 8) + (a.y * img->size);
	if (!img->addr || a.x >= UNIT || a.y >= UNIT || a.x < 0 || a.y < 0)
		return (0);
	color += img->addr[i];
	color += img->addr[++i] << 8;
	color += img->addr[++i] << 16;
	if (color >= 0xFF000000)
		color -= 0xFF000000;
	return (color);
}

/*
** This function reads all the textures that are gonna be used with the mlx xpm
** functions, mlx_xmp_file_to_image.
*/

void			get_textures(t_wolf *w, int x, int y)
{
	w->t[0] = (t_img *)ft_memalloc(sizeof(t_img));
	w->t[0]->img = mlx_xpm_file_to_image(w->mlx, "textures/stone.xpm", &x, &y);
	w->t[0]->addr = mlx_get_data_addr(w->t[0]->img, &w->t[0]->bpp,
			&w->t[0]->size, &w->t[0]->endian);
	w->t[1] = (t_img *)ft_memalloc(sizeof(t_img));
	w->t[1]->img = mlx_xpm_file_to_image(w->mlx, "textures/stone2.xpm", &x, &y);
	w->t[1]->addr = mlx_get_data_addr(w->t[1]->img, &w->t[1]->bpp,
			&w->t[1]->size, &w->t[1]->endian);
	w->t[2] = (t_img *)ft_memalloc(sizeof(t_img));
	w->t[2]->img = mlx_xpm_file_to_image(w->mlx, "textures/stone3.xpm", &x, &y);
	w->t[2]->addr = mlx_get_data_addr(w->t[2]->img, &w->t[2]->bpp,
			&w->t[2]->size, &w->t[2]->endian);
	w->t[3] = (t_img *)ft_memalloc(sizeof(t_img));
	w->t[3]->img = mlx_xpm_file_to_image(w->mlx, "textures/stone4.xpm", &x, &y);
	w->t[3]->addr = mlx_get_data_addr(w->t[3]->img, &w->t[3]->bpp,
			&w->t[3]->size, &w->t[3]->endian);
}

/*
** This function draws a pixel depending on the texture given to it as an image
*/

void			texture_print(t_img *img, t_raycast d, t_img *tex)
{
	t_point	n;

	if (d.dir == 0 || d.dir == 2)
		n = start_point(d.y % 64, d.y_texture);
	else
		n = start_point(d.x % 64, d.y_texture);
	pixel_put(img, d.p, get_pixel_color(tex, n));
}
