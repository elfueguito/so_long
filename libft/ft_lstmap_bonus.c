/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:32:46 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 10:48:09 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new_content = ((*f)(lst->content));
		if (!new)
			return (ft_lstclear(&first, del), NULL);
		new = ft_lstnew(new_content);
		if (!new)
			return (ft_lstclear(&first, del), del(new_content), NULL);
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
