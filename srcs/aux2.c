/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:51:39 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/08 17:43:55 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** This function draws a square of specific size
*/

void	draw_square(t_img *img, t_point init, int size, int interior)
{
	t_point	p;

	p.y = init.y - 1;
	while (++p.y < init.y + size)
	{
		p.x = init.x - 1;
		while (++p.x < init.x + size)
		{
			if (p.x == init.x || p.y == init.y ||
					p.x == size - 1 || p.y == size - 1)
				pixel_put(img, p, 0x88000000);
			else
				pixel_put(img, p, interior);
		}
	}
}

/*
** This function keeps an angle in-between 0 and 360 degrees
*/

double	keep_angle(double angle)
{
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	return (angle);
}

/*
** This function prints all the images onto the window
*/

void	print_images(t_wolf *wolf)
{
	wolf->angle = keep_angle(wolf->angle);
	print_background(wolf, CEILING_COLOR, FLOOR_COLOR);
	fill_area(wolf->map_ui, start_point(wolf->map->img_size.x,
				wolf->map->img_size.y), 0xFFFFFFFF);
	print_image(wolf);
	print_player(wolf, wolf->map_ui);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img->img, 0, 0);
	if (!wolf->map->display)
		return ;
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->minimap->img, 5, 5);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->map_ui->img, 5, 5);
}
