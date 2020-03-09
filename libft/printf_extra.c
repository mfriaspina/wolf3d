/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:17:20 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/07 12:46:05 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		colors(t_flags *flag, char *str)
{
	if (!ft_strncmp("{r}", str, 3))
		ft_putstr(RED);
	else if (!ft_strncmp("{g}", str, 3))
		ft_putstr(GRN);
	else if (!ft_strncmp("{y}", str, 3))
		ft_putstr(YEL);
	else if (!ft_strncmp("{b}", str, 3))
		ft_putstr(BLU);
	else if (!ft_strncmp("{m}", str, 3))
		ft_putstr(MAG);
	else if (!ft_strncmp("{c}", str, 3))
		ft_putstr(CYN);
	else if (!ft_strncmp("{w}", str, 3))
		ft_putstr(WHT);
	else if (!ft_strncmp("{e}", str, 3))
		ft_putstr(END);
	else
		return (invalid(flag, *str));
	flag->size += 2;
	return (3);
}

int		binary(va_list ap, t_flags *flag, intmax_t val)
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
	n = !flag->precision && !val && !flag->hash ? "" : ft_itoa_base(val, 2);
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

int		invalid(t_flags *flag, char c)
{
	int	i;

	i = 0;
	if (flag->left)
		ft_putchar(c);
	while (i < flag->width - 1)
	{
		if (!flag->zero)
			ft_putchar(' ');
		else
			ft_putchar('0');
		i++;
	}
	if (!flag->left)
		ft_putchar(c);
	return (i + 1);
}
