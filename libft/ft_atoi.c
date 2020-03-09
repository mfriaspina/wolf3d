/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:22:42 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 11:39:31 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegative(const char *str, long res, unsigned int i)
{
	while (++i < ft_strlen(str))
	{
		if ((str[i] == '+' || str[i] == ' ') && ft_isdigit(str[i + 1]))
			return (res);
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			return (0);
		if (ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]))
			if (ft_isdigit(str[i + 2]))
				return (res);
		if (!ft_isdigit(str[i]) && str[i] != '-')
			if (ft_isdigit(str[i + 1]))
				return (0);
		if (ft_isdigit(str[ft_strlen(str) - i - 1]))
			if (str[ft_strlen(str) - i - 2] == '-')
			{
				if (res < 0)
					return (0);
				if (ft_isdigit(str[ft_strlen(str) - i - 3]))
					return (res);
				return (res * -1);
			}
	}
	if (res < 0)
		return (-1);
	return (res);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	long			temp;
	long			num;
	long			res;

	i = -1;
	res = 0;
	while (++i < ft_strlen(str))
	{
		if (ft_isdigit(str[ft_strlen(str) - i - 1]))
		{
			temp = 0;
			num = str[ft_strlen(str) - i - 1] - '0';
			while (ft_isdigit(str[ft_strlen(str) - i + temp]))
				temp++;
			while (temp-- > 0)
				num = num * 10;
			if (res + num < res)
				return (ft_isnegative(str, res + num, -1));
			res = res + num;
		}
		else if (ft_isdigit(str[ft_strlen(str) - i - 2]))
			res = 0;
	}
	return (ft_isnegative(str, res, -1));
}
