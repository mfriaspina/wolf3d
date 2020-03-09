/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:54:55 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/03 14:58:38 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;
	unsigned int sum;

	i = 0;
	j = 0;
	if (dstsize > ft_strlen(dst))
	{
		sum = ft_strlen(dst) + ft_strlen(src);
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	else
		sum = dstsize + ft_strlen(src);
	return (sum);
}
