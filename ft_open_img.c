/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:53:56 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:24 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_sprite(t_sprite *sprite, t_mlx_prog *prog)
{
	int	i;

	i = 0;
	prog->images_ptr = ft_calloc(5, sizeof(void *));
	sprite->floor_snow = ft_new_sprite(prog->mlx,
			"sprites/floor_snow.xpm", prog, i++);
	sprite->wall = ft_new_sprite(prog->mlx,
			"sprites/wall.xpm", prog, i++);
	sprite->mushroom = ft_new_sprite(prog->mlx,
			"sprites/mushroom.xpm", prog, i++);
	sprite->player = ft_new_sprite(prog->mlx,
			"sprites/player.xpm", prog, i++);
	sprite->exit = ft_new_sprite(prog->mlx, "sprites/exit.xpm", prog, i);
	return (0);
}

t_image	ft_new_sprite(void *mlx, char *path, t_mlx_prog *prog, int i)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	if (img.ref == NULL)
	{
		ft_printf("Error, impossible to load file : %s\n", path);
		ft_pre_ending(prog);
		exit (0);
	}
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixels,
			&img.line_length, &img.endian);
	prog->images_ptr[i] = img.ref;
	return (img);
}

void	ft_pre_ending(t_mlx_prog *prog)
{
	ft_free_img(prog);
	ft_free(prog->maps);
	mlx_destroy_window(prog->mlx, prog->window.ptr_win);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	prog->mlx = NULL;
}

void	ft_free_img(t_mlx_prog *prog)
{
	int	i;

	i = 0;
	while (prog->images_ptr[i])
	{
		mlx_destroy_image(prog->mlx, prog->images_ptr[i]);
		i++;
	}
	free(prog->images_ptr);
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
