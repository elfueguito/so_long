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

	prog->sprite.pos.x = 0;
	prog->sprite.pos.y = 0;
	ft_sprite_back(&prog->sprite, prog);
	mlx_put_image_to_window(prog->mlx, prog->window.ptr_win, prog->sprite.back_00.ref, prog->sprite.pos.x, prog->sprite.pos.y);
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

    prog.map = map->map;
    prog.mlx = mlx_init();
    prog.window = ft_new_window(prog.mlx, 1920, 1080, "Welcome in the game !");
	//ft_map_start(&prog, map);
    mlx_loop(prog.mlx);
    return (0);
}