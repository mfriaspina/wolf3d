/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:54:33 by mfrias            #+#    #+#             */
/*   Updated: 2019/07/18 14:30:27 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long val, size_t base)
{
	int	size;

	size = 1;
	while (val)
	{
		size++;
		val /= base;
	}
	return (size);
}

char		*ft_itoa_base(unsigned long long val, size_t base)
{
	char	*num;
	int		i;

	num = ft_strnew(get_size(val, base));
	i = 0;
	if (val == 0)
		num[i++] = '0';
	while (val)
	{
		if (val % base >= 10)
			num[i] = ('a' + val % base % 10);
		else
			num[i] = ('0' + val % base);
		i++;
		val /= base;
	}
	num[i] = '\0';
	num = ft_strrev(num);
	return (num);
}
