/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:43:25 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/26 14:19:12 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_wall_up(char **map)
{
	int x;

	x = 0;
	while (map[0][x] != '1')
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_wall_down(char **map, int nb_line)
{
	int x;
		
	x = 0;
	while (map[nb_line - 1][x])
	{
		if (map[nb_line - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_wall_left(char **map)
{
	int y;

	y = 0;
	while (map[y])
	{
		if (map[y][0] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft_wall_right(char **map)
{
	int	y;
	int	i;
	
	y = 0;
	i = ft_strlen(map[0]);
	while (map[y][i])
	{
		if (map[y][i] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft_wall_is_ok(char **map, int nb_line)
{
	if (ft_wall_up(map))
		if(ft_wall_down(map, nb_line))
			if (ft_wall_left(map))
				if (ft_wall_right(map))
					return (1);
	return (0);
}

/*
int ft_wall_is_ok(char **map)
{	
	while (map[x++][1] == 1)
		while (map[ft_strlen(map[i++])][y++] == 1)
			while (map[x--][nb_line] == 1)
				while (map[1][y--] == 1)
					return (1);
	return (0);
}
*/