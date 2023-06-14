/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:51:36 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/08 14:19:12 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_list_img	*ft_lstnew_img(t_image *content)
{
	t_list_img	*new_img;

	new_img = ft_calloc(1, sizeof(t_list_img));
	if (!new_img)
		return (NULL);
	new_img->img = content;
	new_img->next = NULL;
	return (new_img);
}

void	ft_lstadd_back_img(t_list_img *lst, t_list_img *new)
{
	if (!lst)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void	ft_quit_mlx(t_map *map)
{
	ft_free(map);
	write (2, "Error, environnement is missing\n", 32);
	exit(0);
}
