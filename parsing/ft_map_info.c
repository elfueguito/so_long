/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:49:40 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/24 13:50:06 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_P_x(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	while(map[y])
	{
		while (map[y][x])
		{
			
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int ft_P_y(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	while(map[y])
	{
		while (map[y][x])
		{
			
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_E_x(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	while(map[y])
	{
		while (map[y][x])
		{
			
			if (map[y][x] == 'E')
				return (x);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int ft_E_y(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	while(map[y])
	{
		while (map[y][x])
		{
			
			if (map[y][x] == 'E')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_map_info(t_map *map)
{
	map->count_obj = ft_count_obj(map->map);
	ft_printf("%d\n", map->count_obj);
	map->end_x = ft_E_x(map->map);
	map->end_y = ft_E_y(map->map);
	map->start_x = ft_P_x(map->map);
	map->start_y = ft_P_y(map->map);
	map->width = ft_strlen(map->map[0]);
	return (0);
}