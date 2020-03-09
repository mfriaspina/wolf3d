/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:54:40 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/08 20:08:56 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_line(t_wolf *wolf, t_3d d, int column)
{
	int	i;
	int	size;
	int	max;

	size = floor(wolf->distance_const / d.z);
	i = (HEIGHT / 2) - (size / 2) - 1;
	max = (HEIGHT / 2) + (size / 2);
	while (++i < max)
	{
		if (wolf->dir == 0)
			pixel_put(wolf->img, start_point(column, i), 0xFF0000);
		else if (wolf->dir == 1)
			pixel_put(wolf->img, start_point(column, i), 0x00FF00);
		else if (wolf->dir == 2)
			pixel_put(wolf->img, start_point(column, i), 0x0000FF);
		else
			pixel_put(wolf->img, start_point(column, i), 0xFFFF00);
	}
}

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
