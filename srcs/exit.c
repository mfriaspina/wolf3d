/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:11:37 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/11 14:26:10 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (map)
	{
		i = -1;
		while (++i < map->size.y)
			ft_strdel(&map->coor[i]);
		ft_memdel((void **)&(map->coor));
		ft_memdel((void **)&(map));
	}
}

void	free_img(t_wolf *wolf, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(wolf->mlx, img->img);
		ft_memdel((void **)&img);
	}
}

void	free_wolf(t_wolf *wolf)
{
	free_map(wolf->map);
	free_img(wolf, wolf->img);
	free_img(wolf, wolf->minimap);
	free_img(wolf, wolf->map_ui);
	free_img(wolf, wolf->t[0]);
	free_img(wolf, wolf->t[1]);
	free_img(wolf, wolf->t[2]);
	free_img(wolf, wolf->t[3]);
	if (wolf->win)
		mlx_destroy_window(wolf->mlx, wolf->win);
	ft_memdel((void **)&wolf);
	system("leaks wolf3d");
	exit(EXIT_SUCCESS);
}

int		hook_close(t_wolf *wolf)
{
	free_wolf(wolf);
	return (0);
}

void	exit_error(t_wolf *wolf, char *msg)
{
	ft_putendl(msg);
	free_wolf(wolf);
}
