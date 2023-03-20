/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:59 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/09 14:07:16 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_start(t_mlx_prog *prog, t_map *map)
{
	t_position	pos;

	ft_sprite(&prog->sprite, prog);
	ft_init_sprite(prog, &prog->sprite, map);
	mlx_put_image_to_window(prog->mlx, prog->window.ptr_win,
		prog->sprite.player.ref, prog->pos_player.x, prog->pos_player.y);
	return (0);
}

void	*ft_free(char **map)
{
	ssize_t	index;

	index = 0;
	while (map[index])
		index++;
	while (index > 0)
	{
		index--;
		free(map[index]);
	}
	free(map);
	return (NULL);
}

int	ft_redraw_map(void *param)
{
	t_mlx_prog	*prog;

	prog = (t_mlx_prog *) param;
	ft_put_objects(prog);
	ft_check_all(prog);
	ft_finish(prog);
}

int	ft_close_mouse(void)
{
	exit(0);
}

int	ft_game_init(t_map *map)
{
	t_mlx_prog	prog;
	t_position	pos;
	t_data		data;
	t_image		img;

	prog.maps = map;
	prog.window.size.y = map->height;
	prog.window.size.x = map->width;
	prog.pos_player.x = prog.maps->start_x;
	prog.pos_player.y = prog.maps->start_y;
	ft_init_dir(&prog);
	prog.mlx = mlx_init();
	data.mlx = prog.mlx;
	data.window = &prog.window;
	prog.window.ptr_win = mlx_new_window(prog.mlx, map->width * 64,
			map->height * 64, "Welcome in the game !");
	ft_map_start(&prog, map);
	mlx_hook(prog.window.ptr_win, 17, 0, ft_close_mouse, 0);
	mlx_hook(prog.window.ptr_win, 2, 1L << 0, ft_key_pressed, &prog);
	mlx_hook(prog.window.ptr_win, 3, 1L << 1, ft_key_released, &prog);
	mlx_loop_hook(prog.mlx, ft_redraw_map, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
