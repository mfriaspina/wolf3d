/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:49:40 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/10 16:18:59 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	check_start(t_wolf *wolf, t_point p, t_point i, double dir)
{
	t_point n;

	if (p.x)
		exit_error(wolf, "wolf3d : Invalid map, Multiple starting points");
	wolf->angle = dir;
	n.x = (i.x * UNIT) + (UNIT / 2);
	n.y = (i.y * UNIT) + (UNIT / 2);
	wolf->map->coor[i.y][i.x] = '0';
	return (n);
}

t_point	player_position(t_wolf *wolf, t_map *map)
{
	t_point	p;
	t_point	i;

	p = start_point(0, 0);
	i.x = -1;
	while (++i.x < map->size.x)
	{
		i.y = -1;
		while (++i.y < map->size.y)
		{
			if (map->coor[i.y][i.x] == 'N')
				p = check_start(wolf, p, i, 90.0);
			else if (map->coor[i.y][i.x] == 'W')
				p = check_start(wolf, p, i, 180.0);
			else if (map->coor[i.y][i.x] == 'S')
				p = check_start(wolf, p, i, 270.0);
			else if (map->coor[i.y][i.x] == 'E')
				p = check_start(wolf, p, i, 0.0);
		}
	}
	if (!p.x)
		exit_error(wolf, "wolf3d : Invalid map, No starting point");
	return (p);
}

t_point	get_minimap_size(t_wolf *wolf, t_map *map)
{
	int		unit;

	unit = UNIT;
	while (unit > 1)
	{
		if (map->size.x * unit < WIDTH / 2 &&
				map->size.y * unit < HEIGHT / 2)
			break ;
		unit /= 2;
	}
	wolf->unit = unit;
	return (start_point(map->size.x * unit, map->size.y * unit));
}

t_wolf	*start_up(char *location)
{
	t_wolf	*wolf;

	wolf = (t_wolf *)ft_memalloc(sizeof(t_wolf));
	wolf->map = get_map(wolf, location);
	wolf->map->img_size = get_minimap_size(wolf, wolf->map);
	wolf->player = player_position(wolf, wolf->map);
	wolf->img = (t_img *)ft_memalloc(sizeof(t_img));
	wolf->minimap = (t_img *)ft_memalloc(sizeof(t_img));
	wolf->map_ui = (t_img *)ft_memalloc(sizeof(t_img));
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, WIDTH, HEIGHT, "wolf3d");
	wolf->img->img = mlx_new_image(wolf->mlx, WIDTH, HEIGHT);
	wolf->img->addr = mlx_get_data_addr(wolf->img->img, &(wolf->img->bpp),
			&(wolf->img->size), &(wolf->img->endian));
	mini_map(wolf, wolf->minimap, wolf->map_ui, wolf->map);
	wolf->angle_between = FOV / (WIDTH * 1.0);
	wolf->distance_const = (WIDTH / 2) / tan((FOV / 2) * M_PI / 180.0)
		* WALL_HEIGHT;
	get_textures(wolf, UNIT, UNIT);
	return (wolf);
}
