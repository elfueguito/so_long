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

/*int	ft_sprite_map(t_mlx_prog *prog, t_sprite *sprite, t_map *map)
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
				}
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
}*/

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
				prog->pos_player.x = pos.x * 64;
				prog->pos_player.y = pos.y * 64;
			}
			prog->sprite_position.x = pos.x * 64;
			prog->sprite_position.y = pos.y * 64;
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

int	ft_put_wolf(t_mlx_prog *p, t_map *map)
{
	t_position 	pos;
	
	if (p->dir.down == 1 && !ft_take_object(p))
		mlx_put_image_to_window(p->mlx, p->window.ptr_win,
			p->sprite.player.ref, p->pos_player.x, p->pos_player.y);
	if (p->dir.left == 1 && !ft_take_object(p))
		mlx_put_image_to_window(p->mlx, p->window.ptr_win,
			p->sprite.player.ref, p->pos_player.x, p->pos_player.y);
	if (p->dir.up == 1 && !ft_take_object(p))
		mlx_put_image_to_window(p->mlx, p->window.ptr_win,
			p->sprite.player.ref, p->pos_player.x, p->pos_player.y);
	if (p->dir.right == 1 && !ft_take_object(p))
		mlx_put_image_to_window(p->mlx, p->window.ptr_win,
			p->sprite.player.ref, p->pos_player.x, p->pos_player.y);
	return (0);
}

int	ft_reload_map(void *param)
{
	t_mlx_prog			*prog;
	t_position			pos;
	t_map				*map;
	static t_position 	temp_pos;

	prog = (t_mlx_prog *)param;
	map = (t_map *)param;
	pos.y = 0;
	if ((prog->pos_player.x != temp_pos.x
		|| prog->pos_player.y != temp_pos.y))
	{
		while (prog->maps->map[pos.y])
		{
			pos.x = 0;
			while (prog->maps->map[pos.y][pos.x])
			{
				prog->sprite_position.x = pos.x * 64;
				prog->sprite_position.y = pos.y * 64;
				//ft_print_object(prog, &prog->sprite, prog->map, pos);
				ft_take_object(prog);
				//ft_finish(prog, ft_take_object, prog->map);
				ft_print_exit(prog, &prog->sprite, prog->map, pos);
				if (prog->maps->map[pos.y][pos.x] == '0')
					ft_put_floor(prog, &prog->sprite);
				pos.x++;
			}
			pos.y++;
		}
	}
	ft_put_wolf(prog, map);
	temp_pos.x = prog->pos_player.x;
	temp_pos.y = prog->pos_player.y;
	return (0);
}

