/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_clean.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:11 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:39:10 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(int fd, char *line, char *buffer, int i)
{
	int	j;

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	while (read(fd, buffer + i, 1) > 0 && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n' && i > 0)
		buffer[i++] = '\n';
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	if (line != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (buffer[j] != '\n')
				line[j] = buffer[j];
			j++;
		}
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	line = get_line(fd, line, buffer, 0);
	return (line);
}
