/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:01:16 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/06 13:28:46 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	if (ft_strlen(needle) == 0 || haystack == needle)
		return ((char *)haystack);
	while (*haystack != '\0' && count < len)
	{
		while (i < ft_strlen(needle) && ++count < len + 1)
		{
			if (haystack[i] == needle[i])
				i++;
			else
			{
				count = count - i;
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
