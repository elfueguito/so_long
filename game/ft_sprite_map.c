/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:39 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/14 11:39:42 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int	ft_sprite_map(t_mlx_prog *prog, t_sprite *sprite, t_map *map)
{
	t_position pos;

	pos.y = 0;
	while(map->map[pos.y])
	{
		pos.x = 0;
		while(map->map[pos.y][pos.x])
		{
			prog->sprite_position.x = pos.x * 64;
			prog->sprite_position.y = pos.y * 64;
			ft_wall_or_floor(prog, sprite, map->map, pos);
			ft_print_object(prog, sprite, map->map, pos);
			ft_print_exit(prog, sprite, map->map, pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
/*
int	ft_sprite_map_object(t_mlx_prog *prog, t_sprite *sprite, t_map *map)
{
	t_position pos;

	pos.y = 0;
	while(map->map[pos.y])
	{
		pos.x = 0;
		while(map->map[pos.y][pos.x])
		{
			prog->sprite_position.x = pos.x * 64;
			prog->sprite_position.y = pos.y * 64;
			ft_print_object(prog, sprite, map->map, pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}*/

