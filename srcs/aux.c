/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:39:02 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/05 16:47:39 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pixel_put(t_img *img, t_point a, int color)
{
	int	i;

	i = (a.x * img->bpp / 8) + (a.y * img->size);
	if (!img->addr || a.x > WIDTH || a.y > HEIGHT || a.x < 0 || a.y < 0)
		return ;
	img->addr[i] = color;
	img->addr[++i] = color >> 8;
	img->addr[++i] = color >> 16;
	img->addr[++i] = color >> 24;
}

void	fill_area(t_img *img, t_point size, int color)
{
	t_point p;

	p.y = -1;
	while (++p.y < size.y)
	{
		p.x = -1;
		while (++p.x < size.x)
			pixel_put(img, p, color);
	}
}

void	line_img(t_img *img, t_point a, t_point b, int color)
{
	t_point	delta;
	t_point	sign;
	int		error;
	int		delta_error;

	delta.x = ft_abs(a.x - b.x);
	delta.y = ft_abs(a.y - b.y);
	sign.x = b.x < a.x ? 1 : -1;
	sign.y = b.y < a.y ? 1 : -1;
	delta_error = delta.x - delta.y;
	while (b.x != a.x || b.y != a.y)
	{
		pixel_put(img, b, color);
		if ((error = delta_error * 2) > -delta.y)
		{
			delta_error -= delta.y;
			b.x += sign.x;
		}
		if (error < delta.x)
		{
			delta_error += delta.x;
			b.y += sign.y;
		}
	}
}

t_3d	start_3d(int x, int y, int z)
{
	t_3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point	start_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}
