/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:05:54 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 14:35:32 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	stash = NULL;
	read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	int		char_read;

	char_read = 1;
	while (!found_newline(*stash) && char_read != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		char_read = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && char_read == 0) || char_read == -1)
		{
			free(buf);
			return ;
		}
		buf[char_read] = 0;
		add_to_stash(stash, buf, char_read);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, int char_read)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (char_read + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < char_read)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = 0;
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = get_lst_last(*stash);
	last->next = new_node;
}

void	extract_line(t_list	*stash, char	**line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	get_line_size(line, stash);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = 0;
}

void	clean_stash(t_list	**stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return ;
	clean_node->next = NULL;
	last = get_lst_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc((ft_strlen(last->content) - i) + 1);
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = 0;
	free_stash(*stash);
	*stash = clean_node;
	return (free(clean_node->content), free(clean_node));
}
