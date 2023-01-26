/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_is_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:14 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/24 13:52:24 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_up(int x, int y, t_map *map)
{
	if (map->map[y-1][x] == '1')
		return (0);
	return (1);
}

int	ft_check_down(int x, int y, t_map *map)
{
	if (map->map[y+1][x] == '1')
		return (0);
	return (1);
}

int	ft_check_left(int x, int y, t_map *map)
{
	if (map->map[y][x-1] == '1')
		return (0);
	return (1);
}

int	ft_check_right(int x, int y, t_map *map)
{
	if (map->map[y][x+1] == '1')
		return (0);
	return (1);
}

int	ft_move_to_check(int cpt, int x, int y, t_map *map)
{
	int	found;
	if (cpt == map->f_count)
		return (1);
	if (map->map[y][x] == 'C' || map->map[y][x] == 'E')
		map->f_count += 1;
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return (0);
	map->map[y][x] = 'V';
	found = ft_move_to_check(cpt, x, y + 1, map);
	found = ft_move_to_check(cpt, x, y - 1, map);
	found = ft_move_to_check(cpt, x + 1, y, map);
	found = ft_move_to_check(cpt, x - 1, y, map);
	return (found);
}