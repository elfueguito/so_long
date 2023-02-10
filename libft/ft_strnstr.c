/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:08:53 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:22:54 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && !haystack)
		return (NULL);
	if (!*needle)
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		while ((i + j < len) && needle[j] == haystack[i + j] && haystack[i + j])
			j++;
		if (j == ft_strlen(needle))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
