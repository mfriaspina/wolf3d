/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:44:18 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/01 13:58:18 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = (char *)malloc(size + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (i <= size)
	{
		*(new + i) = '\0';
		i++;
	}
	return (new);
}
