/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:43 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 16:45:50 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_is_rectangle(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map [i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_is_valid(char **maps, int nb_line)
{
	if (ft_map_is_rectangle(maps))
	{
		if (ft_wall_is_ok(maps, nb_line))
			return (1);
		else
			write(2, "Error\nthe map had invalid walls\n", 33);
	}
	else
		write(2, "Error\nthe map is not rectangle\n", 32);
	return (0);
}

int	ft_count_line(int fd)
{
	char	*line;
	char	*prev_line;
	int		nb;

	line = get_next_line(fd);
	if (!line)
		return (write(2, "Error\nMap is empty\n", 20));
	prev_line = NULL;
	nb = 0;
	while (line)
	{
		if (prev_line)
			free(prev_line);
		if (line[0])
			nb++;
		prev_line = line;
		line = get_next_line(fd);
	}
	free(line);
	if (prev_line[ft_strlen(prev_line) - 1] == '\n')
		return (free(prev_line), 0);
	free(prev_line);
	return (nb);
}

char	**ft_fill_map(char **map, int nb_line, int fd)
{
	int	i;

	i = 0;
	map = ft_calloc((nb_line + 1), sizeof(char *));
	if (!map)
	{
		free(map);
		return (NULL);
	}
	map[nb_line] = NULL;
	while (i < nb_line)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		if (i != nb_line - 1)
			map[i][ft_strlen(map[i]) - 1] = 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_read_map(t_map *map)
{
	int	fd;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		ft_map_error(fd);
	map->height = ft_count_line(fd);
	if (!map->height || map->height < 3)
		ft_map_error(fd);
	close (fd);
	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		exit(0);
	map->map = ft_fill_map(map->map, map->height, fd);
	close(fd);
	if (!ft_map_is_valid(map->map, map->height)
		|| !ft_check_item(map))
	{
		ft_free(map);
		exit (0);
	}
	return (0);
}

/*int	ft_count_line(int fd)
{
	int		nb;
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	if (!s)
		exit(0);
	nb = 0;
	ft_printf("1st s : %s\n", s);
	while (s != NULL)
	{
		nb++;
		ft_printf("%s\n", s);
		if (!s || (s[0] == '\n' && i == 0 && s[1] == '\0'))
		{
			write (2, "Error, not valid map\n", 22);
			free(s);
			nb++;
			return (nb);
		}
		// if (s && s[0] == '\n' && i == 0)
		// {
		// 	write (2, "Error, not valid mapyouhou\n", 22);
		// 	free(s);
		// 	exit (0);
		// }
		free(s);
		s = get_next_line(fd);
		i++;
	}
	s = get_next_line(fd);
	if (s)
		i++;
	free(s);
	return (nb);
}*/