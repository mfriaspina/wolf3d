/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:11:11 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/06 12:50:25 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned long long n)
{
	int					size;
	unsigned long long	original;
	char				*res;

	size = 0;
	original = n;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	res = ft_strnew(size + 1);
	if (!res)
		return (NULL);
	while (size >= 0)
	{
		res[size--] = '0' + original % 10;
		original = original / 10;
	}
	return (res);
}
