/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:39 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:00:40 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_init_sprite(t_mlx_prog *prog, t_sprite *sprite, t_map *map)
{
	t_position	pos;

	pos.y = 0;
	while (map->map[pos.y])
	{
		pos.x = 0;
		while (map->map[pos.y][pos.x])
		{
			if (map->map[pos.y][pos.x] == 'P')
			{
				prog->pos_player.x = pos.x * 64;
				prog->pos_player.y = pos.y * 64;
			}
			prog->sprite_position.x = pos.x * 64;
			prog->sprite_position.y = pos.y * 64;
			ft_wall_or_floor(prog, sprite, pos);
			ft_print_object(prog, sprite, pos);
			ft_print_exit(prog, sprite, pos);
			ft_print_player(prog, sprite, pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int	ft_print_object(t_mlx_prog *p, t_sprite *s, t_position pos)
{
	if (p->maps->map[pos.y][pos.x] == 'C')
		ft_put_object(p, s);
	return (0);
}

int	ft_print_player(t_mlx_prog *p, t_sprite *s, t_position pos)
{
	if (p->maps->map[pos.y][pos.x] == 'P')
		ft_put_player(p, s);
	return (0);
}

int	ft_print_exit(t_mlx_prog *p, t_sprite *s, t_position pos)
{
	if (p->maps->map[pos.y][pos.x] == 'E')
		ft_put_first_exit(p, s);
	return (0);
}

int	ft_wall_or_floor(t_mlx_prog *p, t_sprite *s, t_position	pos)
{
	if (p->maps->map[pos.y][pos.x] == '1')
		ft_put_wall(p, s);
	if (p->maps->map[pos.y][pos.x] == '0')
		ft_put_floor(p, s);
	return (0);
}
