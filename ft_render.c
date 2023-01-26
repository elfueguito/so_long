/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:13:00 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/26 16:31:42 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}

int ft_close(int keycode, t_vars *vars);
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;
	t_vars	vars;
	
	i = 500;
	j = 600;
	mlx.mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Welcome in the game !");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	vars.mlx = mlx_init();
	vars.win = mlx_new_image(vars.mlx, 1920, 1080, "Welcome to the game !");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
