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
			prog->sprite_position.x = pos.x * 50;
			prog->sprite_position.y = pos.y * 50;
			ft_wall_or_floor(prog, sprite, map->map, pos);
			ft_print_object(prog, sprite, map->map, pos);
			ft_print_exit(prog, sprite, map->map, pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int	ft_reload_map(t_mlx_prog *prog, t_sprite *sprite, t_map *map)
{
	t_position	pos;
	t_position	pos_player;

	pos_player.x = 0;
	pos_player.y = 0;
	pos.y = 0;
	while(map->map[pos.y])
	{
		pos.x = 0;
		while(map->map[pos.y][pos.x])
		{
			if (map->map[pos.y][pos.x] == 'P')
			{
				pos.x = pos_player.x;
				pos.y = pos_player.y;
			}
			prog->sprite_position.x = pos.x * 50;
			prog->sprite_position.y = pos.y * 50;
			if (map->map[pos.y][pos.x] != 1 && map->map[pos.y][pos.x] != 'E')
				ft_put_floor(prog, sprite);
			pos.x++;
		}
		pos.y++;
		ft_print_object(prog, sprite, map->map, pos);
		ft_print_exit(prog, sprite, map->map, pos);
	}
	return (0);
}

