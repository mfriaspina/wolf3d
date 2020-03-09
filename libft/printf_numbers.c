/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:14:25 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/07 12:46:28 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		typex(va_list ap, t_flags *flag, intmax_t val, char c)
{
	char	*n;

	flag->width = flag->hash && flag->zero ? flag->width - 2 : flag->width;
	if (flag->length == 4)
		val = va_arg(ap, unsigned long long);
	else if (flag->length == 3)
		val = va_arg(ap, unsigned long);
	else if (flag->length == 2)
		val = (unsigned short)va_arg(ap, unsigned int);
	else if (flag->length == 1)
		val = (unsigned char)va_arg(ap, unsigned int);
	else
		val = va_arg(ap, unsigned int);
	n = !flag->precision && !val ? "" : ft_itoa_base(val, 16);
	while ((int)ft_strlen(n) < flag->precision)
		n = free_strjoin("0", n, 1);
	n = flag->hash && val && !flag->zero ? free_strjoin("0x", n, 1) : n;
	while ((int)ft_strlen(n) < flag->width)
		n = !flag->left ? free_strjoin(" ", n, 1) : free_strjoin(n, " ", 0);
	if (flag->hash && val && flag->zero)
		n = free_strjoin("0x", n, 1);
	n = flag->zero ? ft_replace(n, '0', ' ') : n;
	n = c == 'X' && ft_strcmp(n, "0") && ft_strcmp(n, "") ?
		ft_strtoupper(n) : n;
	return (clean(n));
}

int		typeo(va_list ap, t_flags *flag, intmax_t val)
{
	char		*n;

	flag->width = flag->hash && flag->zero ? flag->width - 1 : flag->width;
	if (flag->length == 4)
		val = va_arg(ap, unsigned long long);
	else if (flag->length == 3)
		val = va_arg(ap, unsigned long);
	else if (flag->length == 2)
		val = (unsigned short)va_arg(ap, unsigned int);
	else if (flag->length == 1)
		val = (unsigned char)va_arg(ap, unsigned int);
	else
		val = va_arg(ap, unsigned int);
	n = !flag->precision && !val && !flag->hash ? "" : ft_itoa_base(val, 8);
	n = flag->hash && val && !flag->zero ? free_strjoin("0", n, 1) : n;
	while ((int)ft_strlen(n) < flag->precision)
		n = free_strjoin("0", n, 1);
	while ((int)ft_strlen(n) < flag->width)
		n = !flag->left ? free_strjoin(" ", n, 1) : free_strjoin(n, " ", 0);
	if (flag->hash && !flag->precision && flag->zero)
		n = free_strjoin("0", n, 1);
	n = flag->zero && flag->precision == -1 ? ft_replace(n, '0', ' ') : n;
	return (clean(n));
}

int		typeu(va_list ap, t_flags *flag, intmax_t val)
{
	char	*n;

	if (flag->length == 4)
		val = va_arg(ap, unsigned long long);
	else if (flag->length == 3)
		val = va_arg(ap, unsigned long);
	else if (flag->length == 2)
		val = (unsigned short)va_arg(ap, unsigned int);
	else if (flag->length == 1)
		val = (unsigned char)va_arg(ap, unsigned int);
	else
		val = va_arg(ap, unsigned int);
	n = !flag->precision && !val ? "" : ft_utoa(val);
	while ((int)ft_strlen(n) < flag->precision)
		n = free_strjoin("0", n, 1);
	while ((int)ft_strlen(n) < flag->width)
		n = !flag->left ? free_strjoin(" ", n, 1) : free_strjoin(n, " ", 0);
	n = flag->zero && flag->precision == -1 ? ft_replace(n, '0', ' ') : n;
	return (clean_num(n));
}

char	*appends(char *str, t_flags *flag, intmax_t val)
{
	int i;

	i = -1;
	str = flag->zero && flag->precision < 0 ?
		free_strjoin("0", str, 1) : free_strjoin(" ", str, 1);
	while (str[++i])
	{
		if (ft_isdigit(str[i + 1]))
		{
			if (flag->prepend)
				str[i] = flag->prepend == '+' ? '+' : ' ';
			if (val < 0)
				str[i] = '-';
			return (str);
		}
	}
	if (flag->prepend == '+')
	{
		i = flag->left ? 0 : i - 1;
		str[i] = '+';
	}
	return (str);
}

int		typed(va_list ap, t_flags *flag, intmax_t val)
{
	char	*n;

	if (flag->length == 4)
		val = va_arg(ap, long long);
	else if (flag->length == 3)
		val = va_arg(ap, long);
	else if (flag->length == 2)
		val = (short)va_arg(ap, int);
	else if (flag->length == 1)
		val = (char)va_arg(ap, int);
	else
		val = va_arg(ap, int);
	flag->width = flag->prepend || val < 0 ? flag->width - 1 : flag->width;
	n = !flag->precision && !val ? "" : ft_itoa(ft_abs(val));
	while ((int)ft_strlen(n) < flag->precision)
		n = free_strjoin("0", n, 1);
	while ((int)ft_strlen(n) < flag->width)
		n = !flag->left ? free_strjoin(" ", n, 1) : free_strjoin(n, " ", 0);
	n = flag->zero && flag->precision < 0 ? ft_replace(n, '0', ' ') : n;
	if ((flag->prepend || val < 0) && *n != '-')
		n = appends(n, flag, val);
	return (clean_num(n));
}
