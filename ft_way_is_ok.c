/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_is_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:14 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 16:42:30 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_way_is_ok(int cpt, int x, int y, t_map *map)
{
	if ((cpt + 1) == map->f_count)
		return (1);
	if (map->map[y][x] == 'C' || map->map[y][x] == 'E')
		map->f_count += 1;
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return (0);
	map->map[y][x] = 'V';
	ft_way_is_ok(cpt, x, y - 1, map);
	ft_way_is_ok(cpt, x, y + 1, map);
	ft_way_is_ok(cpt, x + 1, y, map);
	ft_way_is_ok(cpt, x - 1, y, map);
	return (0);
}

void	way_is_valid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C' || map->map[y][x] == 'E')
			{
				write(2, "Error\nnot valid path\n", 23);
				ft_free(map);
				exit (0);
			}
			x++;
		}
		y++;
	}
}
