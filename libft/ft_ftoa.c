/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:40:21 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/27 12:28:56 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(double n)
{
	if (n != n)
		return ("nan");
	if ((n - n) != (n - n))
	{
		if (n >= 0)
			return ("inf");
		else
			return ("-inf");
	}
	return (NULL);
}

char		*ft_ftoa(double n, int digits)
{
	char	*res;
	int		i;
	double	fraction;

	if (check(n))
		return (check(n));
	i = (int)n;
	fraction = n - (double)i;
	res = ft_strnew(1);
	if (n < 0)
		res[0] = '-';
	res = ft_strcat(res, ft_itoa(i));
	if (digits != 0)
	{
		res[ft_strlen(res)] = '.';
		fraction = fraction * ft_power(10, digits);
		if (fraction < 0)
			fraction *= -1;
		fraction += 0.5;
		ft_strcat(res, ft_itoa((int)fraction));
		while ((int)ft_strlen(ft_strrchr(res, '.')) <= digits)
			ft_strcat(res, "0");
	}
	res[ft_strlen(res)] = '\0';
	return (res);
}
