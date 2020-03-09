/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:00:48 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 18:21:49 by mfrias           ###   ########.fr       */
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

t_list		*ft_lstsplit(char const *s, char c)
{
	size_t	size;
	t_list	*list;
	t_list	**head;
	size_t	i;

	if (!s)
		return (NULL);
	list = NULL;
	head = &list;
	size = ft_wordcount(s, c);
	while (0 < size)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		*head = ft_lstnew(ft_strsub(s, 0, i), i);
		head = &(*head)->next;
		size--;
		s += i;
	}
	return (list);
}
