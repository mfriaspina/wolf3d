/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:09:45 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/08 20:59:36 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	actual(double angle)
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

static int		check(t_wolf *wolf, t_point size, t_point *a)
{
	t_point	t;

	if (a->y < 0 || a->x < 0 || a->y >= size.y * UNIT || a->x >= size.x * UNIT)
	{
		a->x = INT_MAX;
		a->y = INT_MAX;
		return (0);
	}
	t = start_point(a->x / UNIT, a->y / UNIT);
	if (!wolf->map->coor[t.y][t.x])
		return (1);
	else
		return (0);
}

/*
** This function transforms the view cone to the scale of the minimap
*/

static void		print_view(t_wolf *wolf, t_point p, t_point a, t_3d *real)
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
** It returns a 3d point where the z value is the distance, and:
** (x, y) are the coordinates of the intercept with the wall.
*/

/*
** TODO = There is a discontinuity where the pixels don't align properly.
** This is caused by the transformation from distorted to real
*/

static t_3d		distance(t_wolf *wolf, t_point a, t_point b, double angle)
{
	t_point	distorted;
	t_point	p;
	t_3d	real;

	p = start_point(wolf->player.x, wolf->player.y);
	distorted.x = a.x == INT_MAX || a.y == INT_MAX ? INT_MAX :
		floor(sqrtf(pow(p.x - a.x, 2) + pow(p.y - a.y, 2)));
	distorted.y = b.x == INT_MAX || b.y == INT_MAX ? INT_MAX :
		floor(sqrtf(pow(p.x - b.x, 2) + pow(p.y - b.y, 2)));
	if (distorted.x < distorted.y)
	{
		print_view(wolf, p, a, &real);
		real.z = distorted.x * cos((wolf->angle - angle) * M_PI / 180.0);
		wolf->dir = angle >= 180 ? 3 : 1;
		return (real);
	}
	print_view(wolf, p, b, &real);
	real.z = distorted.y * cos((wolf->angle - angle) * M_PI / 180.0);
	wolf->dir = angle <= 90 || angle >= 270 ? 0 : 2;
	return (real);
}

/*
** This function finds the coordinates at which our ray touches a wall and
** returns the distance from our position to that coordinate.
*/

t_3d			ray_casting(t_wolf *wolf, t_3d p, double orig)
{
	t_point	a;
	t_point	x;
	t_point	b;
	t_point	y;

	a.y = orig < 180 ? (p.y / UNIT) * UNIT - 1 : (p.y / UNIT) * UNIT + UNIT;
	a.x = p.x + (p.y - a.y) / tan(orig * M_PI / 180.0);
	x.y = orig < 180 ? -UNIT : UNIT;
	x.x = x.y / tan(actual(orig) * M_PI / 180.0);
	b.x = orig < 90 || orig > 270 ? (p.x / UNIT) * UNIT + UNIT :
		(p.x / UNIT) * UNIT - 1;
	b.y = p.y + (p.x - b.x) * tan(orig * M_PI / 180.0);
	y.x = orig < 90 || orig > 270 ? UNIT : -UNIT;
	y.y = y.x * tan(actual(orig) * M_PI / 180.0);
	while (check(wolf, wolf->map->size, &a))
	{
		a.y += x.y;
		a.x += x.x;
	}
	while (check(wolf, wolf->map->size, &b))
	{
		b.x += y.x;
		b.y += y.y;
	}
	return (distance(wolf, a, b, orig));
}
