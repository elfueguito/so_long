/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:36:37 by cbacquet          #+#    #+#             */
/*   Updated: 2023/05/24 14:23:47 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update_map(t_mlx_prog *prog)
{
	t_position	pos;

	pos.y = 0;
	pos.x = 0;
	while (prog->maps->map[pos.y])
	{
		while (prog->maps->map[pos.y][pos.x])
		{
			prog->sprite_position.x = pos.x * 64;
			prog->sprite_position.y = pos.y * 64;
			if (prog->maps->map[pos.y][pos.x] != '1'
				&& prog->maps->map[pos.y][pos.x] != 'C')
				ft_put_floor(prog, &prog->sprite);
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
		ft_put_exit(prog);
	}
	return (0);
}

int	ft_put_exit(t_mlx_prog *prog)
{
	t_position	pos;

	pos.y = 0;
	pos.x = 0;
	while (prog->maps->map[pos.y])
	{
		while (prog->maps->map[pos.y][pos.x])
		{
			if (prog->maps->map[pos.y][pos.x] == 'E')
			{
				prog->sprite_position.x = pos.x * 64;
				prog->sprite_position.y = pos.y * 64;
			}
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
	mlx_put_image_to_window(prog->mlx, prog->window.ptr_win,
		prog->sprite.exit.ref,
		prog->sprite_position.x, prog->sprite_position.y);
	return (0);
}
