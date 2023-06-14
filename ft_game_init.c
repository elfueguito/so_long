/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:59 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/14 14:52:34 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_start(t_mlx_prog *prog, t_map *map)
{
	ft_sprite(&prog->sprite, prog);
	ft_init_sprite(prog, &prog->sprite, map);
	mlx_put_image_to_window(prog->mlx, prog->window.ptr_win,
		prog->sprite.player.ref, prog->pos_player.x, prog->pos_player.y);
	return (0);
}

void	ft_free(t_map *map)
{
	ssize_t	index;

	index = 0;
	while (map->map[index])
		index++;
	while (index > 0)
	{
		index--;
		free(map->map[index]);
	}
	free(map->map);
}

int	ft_redraw_map(void *param)
{
	t_mlx_prog	*prog;

	prog = (t_mlx_prog *) param;
	ft_put_objects(prog);
	ft_check_all(prog);
	ft_finish(prog);
	return (0);
}

int	ft_close_mouse(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_prog->sprite.floor_snow.ref);
	mlx_destroy_image(data->mlx, data->mlx_prog->sprite.wall.ref);
	mlx_destroy_image(data->mlx, data->mlx_prog->sprite.player.ref);
	mlx_destroy_image(data->mlx, data->mlx_prog->sprite.exit.ref);
	mlx_destroy_image(data->mlx, data->mlx_prog->sprite.mushroom.ref);
	free(data->mlx_prog->images_ptr);
	mlx_destroy_window(data->mlx, data->window->ptr_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
	ft_free(data->mlx_prog->maps);
	exit(0);
}

int	ft_game_init(t_map *map)
{
	t_mlx_prog	prog;
	t_data		data;

	prog.maps = map;
	prog.window.size.y = map->height;
	prog.window.size.x = map->width;
	if (!ft_big_map(map))
		exit (0);
	// prog.pos_player.x = prog.maps->start_x;
	// prog.pos_player.y = prog.maps->start_y;
	ft_init_dir(&prog);
	prog.mlx = mlx_init();
	if (!prog.mlx)
		ft_quit_mlx(prog.maps);
	data.mlx = prog.mlx;
	data.window = &prog.window;
	data.mlx_prog = &prog;
	prog.window.ptr_win = mlx_new_window(prog.mlx, map->width * 64,
			map->height * 64, "Welcome in the game !");
	if (!prog.window.ptr_win)
		return (free(prog.mlx), ft_quit_mlx(prog.maps), false);
	ft_map_start(&prog, map);
	mlx_hook(prog.window.ptr_win, 17, 0, ft_close_mouse, &data);
	mlx_hook(prog.window.ptr_win, 2, 1L << 0, ft_key_pressed, &prog);
	mlx_loop_hook(prog.mlx, ft_redraw_map, &prog);
	mlx_loop(prog.mlx);
	return (0);
}

// int	ft_run_game(t_map *map)
// {
// 	t_mlx_prog	prog;
// 	t_data		data;

// 	if (!ft_game_init(map))
// 		exit(0);
// 	ft_printf("map : %p\n", map);
// 	ft_printf("height : %d\n", map->height);
// 	ft_printf("width : %d\n", map->width);
// 	ft_printf("p_x : %d\n", prog.maps->start_x);
// 	ft_printf("p_y : %d\n", prog.maps->start_y);
// 	data.mlx = prog.mlx;
// 	data.window = &prog.window;
// 	data.mlx_prog = &prog;
// 	prog.mlx = mlx_init();
// 	if (!prog.mlx)
// 		ft_quit_mlx(prog.maps);
// 	data.mlx = prog.mlx;
// 	data.window = &prog.window;
// 	data.mlx_prog = &prog;
// 	prog.window.ptr_win = mlx_new_window(prog.mlx, map->width * 64,
// 			map->height * 64, "Welcome in the game !");
// 	if (!prog.window.ptr_win)
// 		return (free(prog.mlx), ft_quit_mlx(prog.maps), false);
// 	ft_map_start(&prog, map);
// 	mlx_hook(prog.window.ptr_win, 17, 0, ft_close_mouse, &data);
// 	mlx_hook(prog.window.ptr_win, 2, 1L << 0, ft_key_pressed, &prog);
// 	mlx_loop_hook(prog.mlx, ft_redraw_map, &prog);
// 	mlx_loop(prog.mlx);
// 	return (0);
// }

// bool	ft_game_init(t_map *map)
// {
// 	t_mlx_prog	prog;
// 	// t_data		data;

// 	prog.maps = map;
// 	prog.window.size.y = map->height;
// 	prog.window.size.x = map->width;
// 	if (!ft_big_map(map))
// 		return (false);
// 	prog.pos_player.x = prog.maps->start_x;
// 	prog.pos_player.y = prog.maps->start_y;
// 	ft_init_dir(&prog);
// 	// prog.mlx = mlx_init();
// 	// if (!prog.mlx)
// 	// 	ft_quit_mlx(prog.maps);
// 	// data.mlx = prog.mlx;
// 	// data.window = &prog.window;
// 	// data.mlx_prog = &prog;
// 	// prog.window.ptr_win = mlx_new_window(prog.mlx, map->width * 64,
// 	// 		map->height * 64, "Welcome in the game !");
// 	// if (!prog.window.ptr_win)
// 	// 	return (free(prog.mlx), ft_quit_mlx(prog.maps), false);
// 	// ft_map_start(&prog, map);
// 	// mlx_hook(prog.window.ptr_win, 17, 0, ft_close_mouse, &data);
// 	// mlx_hook(prog.window.ptr_win, 2, 1L << 0, ft_key_pressed, &prog);
// 	// mlx_loop_hook(prog.mlx, ft_redraw_map, &prog);
// 	// mlx_loop(prog.mlx);
// 	return (true);
// }

bool	ft_big_map(t_map *map)
{
	if ((map->height * 64 > 2160) || (map->width * 64 > 3840))
	{
		ft_free(map);
		write(2, "Error\nMap too big\n", 19);
		return (false);
	}
	return (true);
}
