/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:13:25 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/07 12:46:54 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		typef(va_list ap, t_flags *flag, long double val)
{
	char	*n;

	flag->precision = flag->precision == -1 ? 6 : flag->precision;
	if (flag->length == 5)
		val = va_arg(ap, long double);
	else if (flag->length == 6)
		val = 0.0;
	else
		val = va_arg(ap, double);
	flag->width = flag->prepend && val >= 0 ? flag->width - 1 : flag->width;
	n = ft_ftoa(val, flag->precision);
	while ((int)ft_strlen(n) < flag->precision)
		n = free_strjoin("0", n, 1);
	if (flag->zero && val < 0)
		*n = '0';
	while ((int)ft_strlen(n) < flag->width)
		n = !flag->left ? free_strjoin(" ", n, 1) : free_strjoin(n, " ", 0);
	n = flag->zero && flag->precision == -1 ? ft_replace(n, '0', ' ') : n;
	if (flag->prepend && val >= 0)
		n = flag->prepend == '+' ?
			free_strjoin("+", n, 1) : free_strjoin(" ", n, 1);
	*n = flag->zero && val < 0 ? '-' : *n;
	if (flag->hash && ft_strchr(n, '.') == NULL)
		n = free_strjoin(n, ".", 0);
	return (clean(n));
}

int		typep(va_list ap, t_flags *flag)
{
	int		i;
	char	*n;

	n = ft_itoa_base((size_t)va_arg(ap, void *), 16);
	if (!flag->precision && *n == '0')
	{
		ft_putstr("0x");
		return (2);
	}
	while (flag->precision > (int)ft_strlen(n))
		n = ft_strjoin("0", n);
	n = free_strjoin("0x", n, 1);
	i = ft_strlen(n) - 1;
	i = width(flag, i, n);
	ft_strdel(&n);
	return (i);
}

int		typec(va_list ap, t_flags *flag)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(ap, int);
	if (flag->left)
		ft_putchar(c);
	while (++i < flag->width)
	{
		if (!flag->zero)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
	if (!flag->left)
		ft_putchar(c);
	return (i);
}

int		typepercent(t_flags *flag)
{
	int		i;

	i = 0;
	i = width(flag, i, "%");
	return (i);
}

int		typest(va_list ap, t_flags *flag)
{
	char	*n;
	int		i;

	n = va_arg(ap, char *);
	if (flag->zero && n == NULL)
		n = "0";
	if (n == NULL)
		n = "(null)";
	if (flag->precision > -1)
		n = ft_strsub(n, 0, flag->precision);
	i = ft_strlen(n) - 1;
	i = width(flag, i, n);
	return (i);
}
