/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:58:28 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/12 14:04:46 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map(t_map *map)
{
	ft_read_map(map);
	ft_map_info(map);
	ft_way_is_ok(map->count_obj, map->start_x, map->start_y, map);
	way_is_valid(map);
	ft_free(map);
	ft_read_map(map);
}

/*void print_map(char **map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}*/
