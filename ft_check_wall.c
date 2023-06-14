/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:43:25 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/08 12:48:24 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	ft_wall_up(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	ft_wall_down(char **map, int nb_line)
{
	int	x;

	x = 0;
	while (map[nb_line - 1][x])
	{
		if (map[nb_line - 1][x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	ft_wall_left(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y][0] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	ft_wall_right(char **map)
{
	int	y;
	int	i;

	y = 0;
	i = ft_strlen(map[0]);
	while (map[y])
	{
		if (map[y][i - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	ft_wall_is_ok(char **map, int nb_line)
{
	if (ft_wall_up(map) && ft_wall_down(map, nb_line)
		&& ft_wall_left(map) && ft_wall_right(map))
		return (true);
	return (false);
}
