/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:11:37 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/08 16:53:27 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_wolf(t_wolf *wolf)
{
	int	i;

	if (wolf->map)
	{
		i = -1;
		while (++i < wolf->map->size.y)
			ft_strdel(&wolf->map->coor[i]);
		ft_memdel((void **)&(wolf->map->coor));
		ft_memdel((void **)&(wolf->map));
	}
	if (wolf->img)
	{
		mlx_destroy_image(wolf->mlx, wolf->img->img);
		ft_memdel((void **)&wolf->img);
	}
	if (wolf->minimap)
	{
		mlx_destroy_image(wolf->mlx, wolf->minimap->img);
		ft_memdel((void **)&wolf->minimap);
	}
	if (wolf->map_ui)
	{
		mlx_destroy_image(wolf->mlx, wolf->map_ui->img);
		ft_memdel((void **)&wolf->map_ui);
	}
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
