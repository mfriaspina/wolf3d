/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:28:04 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 18:28:56 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
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
