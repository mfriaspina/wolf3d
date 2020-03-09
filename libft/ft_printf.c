/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:55:00 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/07 12:45:52 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(char *format, ...)
{
	va_list	ap;
	int		j;
	t_flags	flag;

	va_start(ap, format);
	j = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flag = (t_flags) {0, 0, 0, 0, 0, -1, 0, 1};
			format += fields(&j, format + 1, ap, &flag);
			if (!*format)
				return (j);
		}
		else
		{
			ft_putchar(*format);
			j++;
		}
		format++;
	}
	va_end(ap);
	return (j);
}
