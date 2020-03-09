/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:05:52 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/02 20:52:50 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*temp;

	len = 0;
	while (s1[len] != '\0')
		len++;
	temp = ft_strnew(len);
	if (!temp)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		temp[len] = s1[len];
		len++;
	}
	return (temp);
}
