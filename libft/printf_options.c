/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:49:38 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/07 12:46:41 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		clean(char *str)
{
	int val;

	ft_putstr(str);
	val = ft_strlen(str);
	if (ft_strcmp("0", str) && ft_strcmp("", str))
		ft_strdel(&str);
	return (val);
}

int		clean_num(char *str)
{
	int val;

	ft_putstr(str);
	val = ft_strlen(str);
	if (ft_strcmp("", str))
		ft_strdel(&str);
	return (val);
}

char	*free_strjoin(char *one, char *two, int i)
{
	char	*temp;

	temp = ft_strjoin(one, two);
	if (*one && *two)
	{
		if (!i)
			free(one);
		else
			free(two);
	}
	return (temp);
}

int		width(t_flags *flag, int i, char *s)
{
	if (flag->left)
		ft_putstr(s);
	while (++i < flag->width)
	{
		if (!flag->zero)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
	if (!flag->left)
		ft_putstr(s);
	return (i);
}

int		ft_intlen(int num)
{
	char	*s;
	int		i;

	s = ft_itoa(num);
	i = ft_strlen(s);
	ft_strdel(&s);
	return (i);
}
