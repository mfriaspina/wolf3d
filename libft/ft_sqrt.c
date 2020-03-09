/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:00:20 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/15 16:42:10 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int initial;

	initial = nb;
	while (nb * nb >= initial)
	{
		if (nb * nb == initial)
			return (nb);
		else
			nb--;
	}
	return (nb);
}
