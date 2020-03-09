/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:40:42 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 18:41:08 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	if (power > 1)
	{
		power--;
		nb = nb * ft_power(nb, power);
	}
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb);
}
