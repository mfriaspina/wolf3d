/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:42:55 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/11 14:34:49 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_collision(t_wolf *wolf, int x, int y)
{
	if (wolf->map->coor[y][x] != '1')
		return (1);
	else
		return (0);
}

void	check_move(t_wolf *wolf, t_point p, int key)
{
	t_point	t;

	if (key == W_KEY)
		t = start_point(p.x + cos(wolf->angle * M_PI / 180.0) * FORWARD_SPEED,
				p.y - sin(wolf->angle * M_PI / 180.0) * FORWARD_SPEED);
	if (key == D_KEY)
		t = start_point(p.x + sin(wolf->angle * M_PI / 180.0) * SPEED,
				p.y + cos(wolf->angle * M_PI / 180.0) * SPEED);
	if (key == A_KEY)
		t = start_point(p.x - sin(wolf->angle * M_PI / 180.0) * SPEED,
				p.y - cos(wolf->angle * M_PI / 180.0) * SPEED);
	if (key == S_KEY)
		t = start_point(p.x - cos(wolf->angle * M_PI / 180.0) * SPEED,
				p.y + sin(wolf->angle * M_PI / 180.0) * SPEED);
	if (check_collision(wolf, t.x / UNIT, t.y / UNIT))
	{
		wolf->player.x = t.x;
		wolf->player.y = t.y;
	}
}

int		key_press(int key, t_wolf *wolf)
{
	if (key == ESC_KEY)
		free_wolf(wolf);
	if (key == W_KEY || key == D_KEY || key == S_KEY || key == A_KEY)
		check_move(wolf, wolf->player, key);
	if (key == LEF_KEY)
		wolf->angle += 5;
	if (key == RIG_KEY)
		wolf->angle -= 5;
	if (key == M_KEY)
		wolf->map->display = !wolf->map->display;
	print_images(wolf);
	return (0);
}
