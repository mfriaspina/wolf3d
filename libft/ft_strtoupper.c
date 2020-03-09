/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:37:32 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/29 13:39:17 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char	*new;
	int		i;

	i = -1;
	new = ft_strnew(ft_strlen(str));
	while (str[++i])
		new[i] = ft_toupper(str[i]);
	return (new);
}
