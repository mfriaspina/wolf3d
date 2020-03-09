/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:11:55 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/03 12:37:00 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		size;
	int		i;

	size = ft_strlen(str);
	rev = ft_strnew(size);
	i = -1;
	while (str[++i])
		rev[--size] = str[i];
	ft_strdel(&str);
	return (rev);
}
