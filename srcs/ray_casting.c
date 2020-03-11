/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:09:45 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/09 17:13:35 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

/*
** This function gets the angle to the values where we can use it for
** trigonometric calulations.
*/

static double		actual(double angle)
{
	if (angle < 180)
		return (180 - angle);
	else
		return (360 - angle);
}

/*
** This function returns 1 if the ray is not touching any walls, and 0 if
** it either touches a wall or goes out of bounds.
*/

static int			check(t_wolf *wolf, t_point size, t_point_d *a,
		double angle)
{
	t_point	t;

	if (a->y < 0 || a->x < 0 || a->y >= size.y * UNIT || a->x >= size.x * UNIT)
	{
		a->x = INT_MAX;
		a->y = INT_MAX;
		return (0);
	}
	t.y = angle >= 180 ? floor(a->y) / UNIT : ceil(a->y) / UNIT;
	t.x = angle <= 90 || angle >= 270 ? floor(a->x) / UNIT : ceil(a->x) / UNIT;
	if (wolf->map->coor[t.y][t.x] != '1')
		return (1);
	else
		return (0);
}

/*
** This function transforms the view cone to the scale of the minimap
*/

static void			print_view(t_wolf *wolf, t_point p, t_point_d a,
		t_raycast *real)
{
	t_point	n;
	t_point	b;

	n = start_point((p.x * wolf->unit) / UNIT, (p.y * wolf->unit) / UNIT);
	b = start_point((a.x * wolf->unit) / UNIT, (a.y * wolf->unit) / UNIT);
	line_img(wolf->map_ui, n, b, 0xAAFFFF00);
	real->x = a.x;
	real->y = a.y;
}

/*
** This function calculates the distance from the position of the player
** to the closest wall. It also prints the view cone in the minimap.
** It returns a struct where the dir value is the distance, dir the direction
** and: (x, y) are the coordinates of the intercept with the wall.
*/

static t_raycast	distance(t_wolf *wolf, t_point_d a, t_point_d b,
		double angle)
{
	double		distorted_x;
	double		distorted_y;
	t_point		p;
	t_raycast	real;

	p = start_point(wolf->player.x, wolf->player.y);
	distorted_x = a.x == INT_MAX || a.y == INT_MAX ? INT_MAX :
		sqrt(pow(p.x - a.x, 2) + pow(p.y - a.y, 2));
	distorted_y = b.x == INT_MAX || b.y == INT_MAX ? INT_MAX :
		sqrt(pow(p.x - b.x, 2) + pow(p.y - b.y, 2));
	if (distorted_x <= distorted_y)
	{
		print_view(wolf, p, a, &real);
		real.dis = distorted_x * cos((wolf->angle - angle) * M_PI / 180.0);
		real.dir = angle >= 180 ? 3 : 1;
		return (real);
	}
	print_view(wolf, p, b, &real);
	real.dis = distorted_y * cos((wolf->angle - angle) * M_PI / 180.0);
	real.dir = angle <= 90 || angle >= 270 ? 0 : 2;
	return (real);
}

/*
** This function finds the coordinates at which our ray touches a wall and
** returns the distance from our position to that coordinate.
*/

t_raycast			ray_casting(t_wolf *wolf, t_point p, double angle)
{
	t_point_d	a;
	t_point_d	x;
	t_point_d	b;
	t_point_d	y;

	a.y = angle < 180 ? (p.y / UNIT) * UNIT - 1 : (p.y / UNIT) * UNIT + UNIT;
	a.x = p.x + (p.y - a.y) / tan(angle * M_PI / 180.0);
	x.y = angle < 180 ? -UNIT : UNIT;
	x.x = x.y / tan(actual(angle) * M_PI / 180.0);
	b.x = angle < 90 || angle > 270 ? (p.x / UNIT) * UNIT + UNIT :
		(p.x / UNIT) * UNIT - 1;
	b.y = p.y + (p.x - b.x) * tan(angle * M_PI / 180.0);
	y.x = angle < 90 || angle > 270 ? UNIT : -UNIT;
	y.y = y.x * tan(actual(angle) * M_PI / 180.0);
	while (check(wolf, wolf->map->size, &a, angle))
	{
		a.y += x.y;
		a.x += x.x;
	}
	while (check(wolf, wolf->map->size, &b, angle))
	{
		b.x += y.x;
		b.y += y.y;
	}
	return (distance(wolf, a, b, angle));
}
