/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:46 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:16:05 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_obj_check(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_finish(t_mlx_prog *prog)
{
	if (prog->maps->map[(prog->pos_player.y) / 64]
		[(prog->pos_player.x) / 64] == 'E')
	{
		if (ft_obj_check(prog->maps->map))
		{
			write(1, "Well done", 9);
			ft_free(prog->maps->map);
			exit(0);
		}
	}
	return (0);
}
