/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:49:04 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 15:12:00 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_increase_count(char pos, t_count *count)
{
	if (pos == 'P')
		count->p += 1;
	else if (pos == 'E')
		count->e += 1;
	else if (pos == 'C')
		count->c += 1;
}

bool	ft_check_item(t_map *map)
{
	int		y;
	int		x;
	t_count	count;

	y = 0;
	count.p = 0;
	count.e = 0;
	count.c = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'C')
				ft_increase_count(map->map[y][x], &count);
			x++;
		}
		y++;
	}
	map->count_obj = count.c;
	if (count.p != 1 || count.e != 1 || count.c == 0
		|| ft_allowed_items(map->map) == false)
		return (write(2, "Error, items are invalid\n", 26), false);
	return (true);
}

bool	ft_allowed_items(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'C'
				&& map[y][x] != '1' && map[y][x] != '0')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
// int	ft_check_exit(char **map)
// {
// 	int	y;
// 	int	x;
// 	int	count_e;

// 	y = 0;
// 	count_e = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == 'E')
// 				count_e++;
// 			x++;
// 		}
// 	y++;
// 	}
// 	if (count_e > 1)
// 		return (0);
// 	return (1);
// }

// int	ft_count_obj(char **map)
// {
// 	int	y;
// 	int	x;
// 	int	count;

// 	y = 0;
// 	count = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == 'C')
// 				count++;
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return (count);
// }

// bool	ft_check_objects(char **map)
// {
// 	if (ft_count_obj(map) > 0)
// 		return (true);
// 	return (false);
// }

// int	ft_check_item(char **map)
// {
// 	if (ft_check_enter(map) && ft_check_objects(map)
// 		&& ft_check_exit(map))
// 		return (1);
// 	else
// 		write(2, "Error, items are invalid\n", 26);
// 	return (0);
// }
