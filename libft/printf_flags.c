/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:13:47 by mfrias            #+#    #+#             */
/*   Updated: 2019/08/07 12:46:18 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	types(char *c, va_list ap, t_flags *flag)
{
	flag->width = ft_abs(flag->width);
	if (*c == '%')
		return (typepercent(flag));
	else if (*c == 'd' || *c == 'i' || *c == 'D')
		return (typed(ap, flag, 0));
	else if (*c == 'u' || *c == 'U')
		return (typeu(ap, flag, 0));
	else if (*c == 'o' || *c == 'O')
		return (typeo(ap, flag, 0));
	else if (*c == 'x' || *c == 'X')
		return (typex(ap, flag, 0, *c));
	else if (*c == 's')
		return (typest(ap, flag));
	else if (*c == 'c')
		return (typec(ap, flag));
	else if (*c == 'p')
		return (typep(ap, flag));
	else if (*c == 'f')
		return (typef(ap, flag, 0.0));
	else if (*c == '{')
		return (colors(flag, c));
	else if (*c == 'b')
		return (binary(ap, flag, 0));
	return (invalid(flag, *c));
}

static int	precision(char *format, t_flags *flag, va_list ap)
{
	if (!ft_isdigit(*(format + 1)))
	{
		flag->precision = format[1] == '*' ? (va_arg(ap, int)) : 0;
		if (*(format + 1) == '*')
			return (2);
		return (1);
	}
	flag->precision = ft_atoi(format + 1);
	if (format[1] == '0' && flag->precision != 0)
		return (ft_intlen(flag->precision) + 2);
	else
		return (ft_intlen(flag->precision) + 1);
}

static int	more(char *format, t_flags *flag, va_list ap)
{
	if (*format == '.')
		return (precision(format, flag, ap));
	else if (ft_isdigit(*format))
	{
		flag->width = ft_atoi(format);
		return (ft_intlen(flag->width));
	}
	else if (*format == '*')
		flag->width = va_arg(ap, int);
	else if (*format == 'L')
		flag->length = *(format + 1) == 'l' || *(format + 1) == 'L' ||
			flag->length == 3 || flag->length == 6 ? 6 : 5;
	else
	{
		*format != '\0' ? flag->size-- : flag->size;
		return (0);
	}
	return (1);
}

static int	flags(char *format, t_flags *flag, va_list ap)
{
	if (*format == '-')
		flag->left = 1;
	else if (*format == '0')
		flag->zero = 1;
	else if (*format == '#')
		flag->hash = 1;
	else if (*format == '+')
		flag->prepend = '+';
	else if (*format == ' ')
		flag->prepend = flag->prepend != '+' ? ' ' : '+';
	else if ((*format == 'l' && *(format + 1) == 'l') || *format == 'j')
		flag->length = flag->length > 4 ? flag->length : 4;
	else if ((*format == 'l' && *(format + 1) != 'l') || *format == 'z')
		flag->length = flag->length > 3 ? flag->length : 3;
	else if (*format == 'h' && *(format + 1) != 'h')
		flag->length = flag->length > 2 ? flag->length : 2;
	else if (*format == 'h' && *(format + 1) == 'h')
		flag->length = flag->length > 1 ? flag->length : 1;
	else
		return (more(format, flag, ap));
	if (*format == format[1])
		return (2);
	return (1);
}

int			fields(int *j, char *format, va_list ap, t_flags *flag)
{
	int		last;

	if (*format == 'U' || *format == 'O' || *format == 'D')
	{
		flag->length = 3;
		*j += types(format, ap, flag);
	}
	else
	{
		last = flags(format, flag, ap);
		if (!last)
		{
			if (!*format)
				return (flag->size);
			*j += types(format, ap, flag);
			return (++flag->size);
		}
		flag->zero = flag->left ? 0 : flag->zero;
		flag->size += last;
		flag->left = flag->width < 0 ? 1 : flag->left;
		fields(j, format + last, ap, flag);
	}
	return (flag->size);
}
