/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:55:57 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/10 14:37:46 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** This function initializes a minimap
*/

void	mini_map(t_wolf *wolf, t_img *img, t_img *ui, t_map *map)
{
	t_point i;

	img->img = mlx_new_image(wolf->mlx, map->img_size.x, map->img_size.y);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->size), &(img->endian));
	fill_area(img, start_point(map->img_size.x, map->img_size.y), 0xDD000000);
	i.y = 0;
	while (i.y < map->size.y * wolf->unit)
	{
		i.x = 0;
		while (i.x < map->size.x * wolf->unit)
		{
			if (map->coor[i.y / wolf->unit][i.x / wolf->unit] == '1')
				draw_square(img, i, wolf->unit, 0x88444444);
			else
				draw_square(img, i, wolf->unit, 0x88FFFFFF);
			i.x += wolf->unit;
		}
		i.y += wolf->unit;
	}
	ui->img = mlx_new_image(wolf->mlx, map->img_size.x, map->img_size.y);
	ui->addr = mlx_get_data_addr(ui->img, &(ui->bpp),
			&(ui->size), &(ui->endian));
}

/*
** This function reads a file
*/

char	*read_file(t_wolf *wolf, char *in)
{
	char	c[2];
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(in, O_RDONLY);
	if (fd < 0)
		exit_error(wolf, "wolf3d: No such file");
	c[1] = 0;
	str = ft_strdup("");
	while (read(fd, c, 1))
	{
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	close(fd);
	return (str);
}

/*
** This function returns the size of the map
*/

t_point	get_size(char *content)
{
	int		i;
	int		max;
	t_point	size;

	size = start_point(2, 2);
	i = -1;
	max = 2;
	while (content[++i])
	{
		if (ft_isalnum(content[i]))
			max++;
		if (content[i] == '\n')
		{
			if (max > size.x)
				size.x = max;
			max = 2;
			size.y++;
		}
	}
	return (size);
}

/*
** This function saves the type of the coordinates of the map
*/

void	start_map(t_map *map, char *content)
{
	int		i;
	t_point	p;

	i = -1;
	while (++i < map->size.x)
	{
		map->coor[0][i] = '1';
		map->coor[map->size.y - 1][i] = '1';
	}
	p = start_point(1, 1);
	i = -1;
	while (content[++i])
	{
		if (ft_isalnum(content[i]))
			map->coor[p.y][p.x++] = content[i];
		if (content[i] == '\n')
		{
			p.y++;
			p.x = 1;
		}
	}
}

/*
** This function returns a struct that describe a map
*/

t_map	*get_map(t_wolf *wolf, char *file)
{
	char	*content;
	t_map	*map;
	int		i;

	content = read_file(wolf, file);
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = get_size(content);
	map->coor = (char **)ft_memalloc(sizeof(char *) * map->size.y);
	i = -1;
	while (++i < map->size.y)
		map->coor[i] = ft_strnew(map->size.x);
	i = -1;
	while (++i < map->size.y)
	{
		map->coor[i][0] = '1';
		map->coor[i][map->size.x - 1] = '1';
	}
	start_map(map, content);
	free(content);
	map->display = 1;
	return (map);
}
