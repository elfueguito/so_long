/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:42:06 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:23:09 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_result;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	s += start;
	len_result = 0;
	while (s[len_result] && len_result < len)
		len_result++;
	str = (char *)malloc(sizeof(char) * (++len_result));
	if (!str)
		return (NULL);
	if (str != NULL)
		ft_strlcpy(str, s, len_result);
	return (str);
}
