/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:29:01 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/10 12:41:04 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *original, char new, char old)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_strnew(ft_strlen(original));
	while (original[++i])
	{
		if (original[i] == old)
			str[i] = new;
		else
			str[i] = original[i];
	}
	ft_strdel(&original);
	return (str);
}
