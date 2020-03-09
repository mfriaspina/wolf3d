/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:40:14 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/07 18:19:10 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	**head;

	new = NULL;
	head = &new;
	while (lst)
	{
		*head = (t_list *)ft_memalloc(sizeof(t_list));
		if (!*head)
			return (NULL);
		*head = (*f)(lst);
		head = &(*head)->next;
		lst = lst->next;
	}
	return (new);
}
