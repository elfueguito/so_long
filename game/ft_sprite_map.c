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
			if (map->map[pos.y][pos.x] == 'P')
			{
				prog->pos_player.x = pos.x * 50;
				prog->pos_player.y = pos.y * 50;
			}
			prog->sprite_position.x = pos.x * 50;
			prog->sprite_position.y = pos.y * 50;
			ft_wall_or_floor(prog, sprite, map->map, pos);
			ft_print_object(prog, sprite, map->map, pos);
			ft_print_exit(prog, sprite, map->map, pos);
			ft_print_player(prog, sprite, map->map, pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int	ft_reload_map(t_mlx_prog *prog, t_sprite *sprite, t_map *map)
{
	t_position	pos;
	int 		key;

	if(ft_move_up(prog))
	{
		pos.y = 0;
		while(map->map[pos.y])
		{
			pos.x = 0;
			while(map->map[pos.y][pos.x])
			{
/*				if (map->map[pos.y][pos.x] == 'P')
				{
					pos.x = pos_player.x;
					pos.y = pos_player.y;
				}*/
				prog->sprite_position.x = pos.x * 50;
				prog->sprite_position.y = pos.y * 50;
				if (map->map[pos.y][pos.x] == '0' || map->map[pos.y][pos.x] == 'P')
					ft_put_floor(prog, sprite);
				pos.x++;
			}
			pos.y++;
			ft_print_object(prog, sprite, map->map, pos);
			ft_print_exit(prog, sprite, map->map, pos);
			//ft_print_player(prog, sprite, map->map, pos);
		}
		mlx_put_image_to_window(prog->mlx, prog->window.ptr_win, sprite->player.ref, prog->pos_player.x, prog->pos_player.y);
	}
	return (0);
}

