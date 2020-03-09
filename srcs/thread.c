/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:11:43 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/08 13:35:49 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		*thread_command(void *thread)
{
	t_thread	*th;
	t_3d		d;

	th = (t_thread *)thread;
	while (th->c < (WIDTH / THREAD * (th->id + 1)))
	{
		d = ray_casting(th->w, th->w->player, th->angle);
		draw_line(th->w, d, th->c);
		th->angle = keep_angle(th->angle - th->w->angle_between);
		th->c++;
	}
	return (NULL);
}

t_thread	*thread_create(t_wolf *wolf, int id)
{
	t_thread	*t;

	t = (t_thread *)ft_memalloc(sizeof(t_thread));
	t->id = id;
	t->w = wolf;
	t->angle = keep_angle(wolf->angle + (FOV / 2) -
			(id * WIDTH / THREAD * wolf->angle_between));
	t->c = id * (WIDTH / THREAD);
	return (t);
}
