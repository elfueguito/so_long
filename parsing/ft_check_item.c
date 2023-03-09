/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:49:04 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/09 13:51:18 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_enter(char **map)
{
	int	y;
	int	x;
	int	count_p;

	y = 0;
	count_p = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				count_p++;
			x++;
		}
		y++;
	}
	if (count_p > 1)
		return (0);
	return (1);
}

int	ft_check_exit(char **map)
{
	int	y;
	int	x;
	int	count_e;

	y = 0;
	count_e = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				count_e++;
			x++;
		}
	y++;
	}
	if (count_e > 1)
		return (0);
	return (1);
}

int	ft_count_obj(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

int	ft_check_objects(char **map)
{
	if (ft_count_obj(map) > 0)
		return (1);
	return (0);
}

int	ft_check_item(char **map)
{
	if (ft_check_enter(map))
		if (ft_check_objects(map))
			if (ft_check_exit(map))
				return (1);
	return (0);
}
