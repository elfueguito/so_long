/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:53:56 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:15:06 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_sprite(t_sprite *sprite, t_mlx_prog *prog)
{
	sprite->floor_snow = ft_new_sprite(prog->mlx, "sprites/floor_snow.xpm");
	sprite->wall = ft_new_sprite(prog->mlx, "sprites/wall.xpm");
	sprite->mushroom = ft_new_sprite(prog->mlx, "sprites/mushroom.xpm");
	sprite->player = ft_new_sprite(prog->mlx, "sprites/player.xpm");
	sprite->exit = ft_new_sprite(prog->mlx, "sprites/exit.xpm");
	//sprite->wolf_left = ft_new_sprite(prog->mlx, "sprites/wolf_left.xpm");
	//sprite->wolf_right = ft_new_sprite(prog->mlx, "sprites/wolf_right.xpm");
	//sprite->wolf_back = ft_new_sprite(prog->mlx, "sprites/wolf_back.xpm");
	return (0);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixels,
			&img.line_length, &img.endian);
	return (img);
}

int	ft_put_objects(t_mlx_prog *prog)
{
	t_position	pos;

	pos.y = 0;
	while (prog->maps->map[pos.y])
	{
		pos.x = 0;
		while (prog->maps->map[pos.y][pos.x])
		{
			prog->sprite_position.x = pos.x * 64;
			prog->sprite_position.y = pos.y * 64;
			if (prog->maps->map[pos.y][pos.x] == 'C')
				ft_put_object(prog, &prog->sprite);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
