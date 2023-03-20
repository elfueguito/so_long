/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:43 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/20 13:52:45 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_is_rectangle(char **map)
{
	int	i;

	i = 0;
	while (map [i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_is_valid(char **maps, int nb_line, t_map *map)
{
	if (ft_map_is_rectangle(maps))
		if (ft_wall_is_ok(maps, nb_line))
			return (1);
	return (0);
}

int	ft_count_line(int fd)
{
	char	c;
	int		count;

	count = 0;
	while (read(fd, &c, 1 > 0))
	{
		if (c == '\n')
			count++;
	}
	return (count + 1);
}

char	**ft_fill_map(char **map, int nb_line, int fd)
{
	int	i;

	i = 0;
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (free(map), NULL);
	map[nb_line] = NULL;
	while (i < nb_line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}

char	**ft_read_map(t_map *map)
{
	int	fd;

	fd = open(map->file, O_RDONLY);
	map->height = ft_count_line(fd);
	close (fd);
	fd = open(map->file, O_RDONLY);
	map->map = ft_fill_map(map->map, map->height, fd);
	close(fd);
	if (!ft_map_is_valid(map->map, map->height, map)
		|| !ft_check_item(map->map))
	{
		write(1, "Error, not valid map \n", 23);
		exit (0);
	}
	return (0);
}
