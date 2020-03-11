/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:54:40 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/11 14:25:51 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** This function draws each column of the main image
*/

void	draw_line(t_wolf *wolf, t_raycast d, int column)
{
	int		i;
	int		size;
	int		max;
	int		start;

	size = wolf->distance_const / d.dis;
	i = ((HEIGHT - size) / 2) - 1;
	start = i + 1;
	max = (HEIGHT + size) / 2;
	while (++i < max)
	{
		d.y_texture = ((i - HEIGHT / 2 + size / 2) * UNIT) / size;
		d.p = start_point(column, i);
		if (d.dir == 0)
			texture_print(wolf->img, d, wolf->t[0]);
		else if (d.dir == 1)
			texture_print(wolf->img, d, wolf->t[1]);
		else if (d.dir == 2)
			texture_print(wolf->img, d, wolf->t[2]);
		else
			texture_print(wolf->img, d, wolf->t[3]);
	}
}

/*
** This function draws the player onto the minimap
*/

void	print_player(t_wolf *wolf, t_img *img)
{
	t_point i;
	t_point n;

	i.x = wolf->player.x - 5;
	while (++i.x < wolf->player.x + 4)
	{
		i.y = wolf->player.y - 5;
		while (++i.y < wolf->player.y + 4)
		{
			n.x = (i.x * wolf->unit) / UNIT;
			n.y = (i.y * wolf->unit) / UNIT;
			pixel_put(img, n, 0x66FF0000);
		}
	}
}

/*
** This function draws the main image with a number of threads
*/

void	print_image(t_wolf *wolf)
{
	pthread_t	t[THREAD];
	t_thread	*thread[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		thread[i] = thread_create(wolf, i);
		pthread_create(t + i, NULL, thread_command, thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(t[i], NULL);
		free(thread[i]);
		i++;
	}
}

void	print_background(t_wolf *wolf, int ceil, int floor)
{
	t_point	p;

	p.y = -1;
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
		{
			if (p.y < HEIGHT / 2)
				pixel_put(wolf->img, p, ceil);
			else
				pixel_put(wolf->img, p, floor);
		}
	}
}
