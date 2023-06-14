/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:49:40 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 16:46:11 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_pos(char **map, char search, int *pos_x, int *pos_y)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == search)
			{
				*pos_x = x;
				*pos_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_map_info(t_map *map)
{
	map->f_count = 0;
	ft_pos(map->map, 'E', &(map->end_x), &(map->end_y));
	ft_pos(map->map, 'P', &(map->start_x), &(map->start_y));
	map->width = ft_strlen(map->map[0]);
	return (0);
}

void	ft_map_error(int fd)
{
	write(2, "Error\nnot valid map\n", 21);
	close(fd);
	exit(0);
}
