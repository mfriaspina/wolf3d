/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:58:17 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/05 17:33:42 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (haystack == needle)
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		while (i < ft_strlen(needle))
		{
			if (haystack[i] == needle[i])
				i++;
			else
			{
				i = 0;
				break ;
			}
		}
		if (i == ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
