/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:30:22 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/05 13:44:26 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_unit;

	new_unit = (t_list *)malloc(sizeof(t_list));
	if (!new_unit)
		return (NULL);
	new_unit->content = content;
	new_unit->next = NULL;
	return (new_unit);
}
