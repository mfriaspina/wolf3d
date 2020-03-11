/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:00:01 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/09 16:56:00 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(int argc, char **argv)
{
	t_wolf	*wolf;

	if (argc != 2)
	{
		ft_putendl("usage: wolf3d [map]");
		return (EXIT_FAILURE);
	}
	wolf = start_up(argv[1]);
	print_images(wolf);
	mlx_hook(wolf->win, 2, 0, key_press, wolf);
	mlx_hook(wolf->win, 17, 0, hook_close, wolf);
	mlx_loop(wolf->mlx);
	return (EXIT_SUCCESS);
}
