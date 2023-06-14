/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:46 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 16:38:17 by cbacquet         ###   ########.fr       */
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
			write(1, "\nWell done !\n", 13);
			mlx_destroy_image(prog->mlx, prog->sprite.floor_snow.ref);
			mlx_destroy_image(prog->mlx, prog->sprite.wall.ref);
			mlx_destroy_image(prog->mlx, prog->sprite.player.ref);
			mlx_destroy_image(prog->mlx, prog->sprite.exit.ref);
			mlx_destroy_image(prog->mlx, prog->sprite.mushroom.ref);
			free(prog->images_ptr);
			mlx_destroy_window(prog->mlx, prog->window.ptr_win);
			mlx_destroy_display(prog->mlx);
			free(prog->mlx);
			prog->mlx = NULL;
			ft_free(prog->maps);
			exit(0);
		}
	}
	return (0);
}
