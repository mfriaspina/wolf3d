/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:51:57 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 18:05:33 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	num;
	int	i;
	int	size;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		size = 0;
		while (s[i++] != c && s[i])
			size = 1;
		if (size)
			num++;
	}
	return (num);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	size;
	char	**arr;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	size = ft_wordcount(s, c);
	if (!(arr = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (0 < size)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		if ((arr[j] = ft_strsub(s, 0, i)) == NULL)
			return (NULL);
		j++;
		size--;
		s += i;
	}
	return (arr);
}
