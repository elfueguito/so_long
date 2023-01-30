/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:13:00 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:26 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}

int ft_close(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	return (0);
}

int ft_close_mouse(void)
{
	exit(0);
}
/*
int	ft_move(int keycode, t_data *img)
{
	int	i;
	int	j;
	
	i = 500;
	j = 500;
	my_mlx_pixel_put(img, i, j, 0x00FF0000);
	if (keycode == 13)
	{
		my_mlx_pixel_put(img, i - 1, j, 0x00FF0000);
	}
	if (keycode == 0)
	{
		my_mlx_pixel_put(img, i - 1, j, 0x00FF0000);
	}	
	if (keycode == 1)
	{
		my_mlx_pixel_put(img, i, j + 1, 0x00FF0000);
	}
	if (keycode == 2)
	{
		my_mlx_pixel_put(img, i + 1, j, 0x00FF0000);
	}
	return (0);
}
*/
int main (void)
{
	t_data	img;
	int		i;
	int		j;
	//t_vars	vars;
	
	i = 500;
	j = 600;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Welcome in the game !");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	while (i <= 600)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		i++;
	}
	while (i <= 700 & j >= 500)
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
