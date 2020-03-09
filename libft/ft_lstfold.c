/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:27:16 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 17:58:43 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(void *(*f)(t_list *elem, void *), t_list *lst)
{
	void *res;

	if (!lst)
		return (NULL);
	res = lst->content;
	lst = lst->next;
	while (lst)
	{
		res = (*f)(lst, res);
		lst = lst->next;
	}
	return (res);
}
