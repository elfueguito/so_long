/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:49:04 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/26 14:19:14 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_enter(char **map)
{
	int	y;
	int	x;
	int	count_P;
	
	y = 0;
	x = 0;
	count_P = 0;
	while(map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				count_P++;
			x++;
		}
		y++;
	}	
	if (count_P > 1)
		return (0);
	return(1);
}

int	ft_check_exit(char **map)
{
	int	y;
	int	x;
	int	count_E;
	
	y = 0;
	x = 0;
	count_E = 0;
	while(map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				count_E++;
			x++;
		}
	y++;
	}	
	if (count_E > 1)
		return (0);
	return(1);
}

int	ft_count_obj(char **map)
{
	int	y;
	int	x;
	int	count;
	
	y = 0;
	x = 0;
	count = 0;
	while(map[y])
	{
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
	return(0);
}