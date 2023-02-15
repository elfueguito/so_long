/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:21:59 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/07 18:22:01 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int ft_map_start(t_mlx_prog *prog, t_map *map)
{
    t_position  pos;
    //prog->sprite.pos.x = 0;
    //prog->sprite.pos.y = 0;
    ft_sprite(&prog->sprite, prog);
    ft_sprite_map(prog, &prog->sprite, map);
	mlx_put_image_to_window(prog->mlx, prog->window.ptr_win, prog->sprite.player.ref, prog->sprite.pos.x, prog->sprite.pos.y);
    //ft_sprite_map_object(prog, &prog->sprite, map);
    return (0);
}

void    *ft_free(char **map)
{
    ssize_t index;

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

int ft_game_init(t_map *map)
{
    t_mlx_prog  prog;
    t_position  pos;
    t_data		data;
	t_image		img;

    prog.map = map->map;
    prog.mlx = mlx_init();
    //prog.window = ft_new_window(prog.mlx, map->width * 64, map->height *64, "Welcome in the game !");
    data.mlx = prog.mlx;
	prog.window.ptr_win = mlx_new_window(prog.mlx, map->width * 64, map->height * 64, "Welcome in the game !");
	prog.window.size.x = map->width;
	prog.window.size.y = map->height;
	data.window = &prog.window;
	mlx_hook(prog.window.ptr_win, 2, 1L<<0, ft_close, &data);
	mlx_hook(prog.window.ptr_win, 17, 0, ft_close_mouse, 0);
    ft_map_start(&prog, map);
    mlx_loop(prog.mlx);
    return (0);
}
