/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:29:25 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/07 14:29:32 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
/*
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}

int main (void)
{
	t_data	img;
	int		i;
	int		j;
	char	*relative_path = "./space_background/background_1.xpm";
	int		img_width;
	int		img_height;

	//t_vars	vars;
	
	i = 500;
	j = 600;
	img_width = 800;
	img_height = 800;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Welcome in the game !");
	img.img = mlx_xpm_file_to_image(img.mlx, relative_path, &img_width, &img_height);
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	while (i <= 600)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		i++;
	}
	while (i <= 700 && j >= 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i++;
		j--;
	}
	while (i >= 500)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i--;
	}
	
	//ft_move(keycode, &img);
	//mlx_key_hook(img.mlx_win, ft_close, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	//mlx_loop_hook(img.mlx, ft_move, &img);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_close_mouse, 0);
	mlx_loop(img.mlx);
}
*/

int main (int argc, char **argv)
{
	t_map	map;

/*	if (argc == 2)
	{
		write(1, "Map Error", 10);
		return (0);
	}
	map.file = argv[1];*/
	ft_init_map(&map);
	ft_game_init(&map);
	ft_free(map.map);
	return (0);
}