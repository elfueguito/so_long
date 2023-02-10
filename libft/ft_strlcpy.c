/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:08:07 by cbacquet          #+#    #+#             */
/*   Updated: 2022/11/15 13:42:00 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (dstsize == 0)
		return (len_src);
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
