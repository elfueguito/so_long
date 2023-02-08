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

#include "../so_long.h"

int	ft_way_is_ok(int cpt, int x, int y, t_map *map)
{
	int	found;
	
	if (cpt == map->f_count)
		return (1);
	if (map->map[y][x] == 'C' || map->map[y][x] == 'E')
		map->f_count += 1;
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return (0);
	map->map[y][x] = 'V';
	found = ft_way_is_ok(cpt, x, y - 1, map);
	found = ft_way_is_ok(cpt, x, y + 1, map);
	found = ft_way_is_ok(cpt, x + 1, y, map);
	found = ft_way_is_ok(cpt, x - 1, y, map);
	return (found);
}