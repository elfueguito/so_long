/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:17:49 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/30 14:40:27 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

t_data	ft_window(void *mlx, int width, int height, char *name)
{
	t_data	img;
	
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Welcome in the game !");
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_close_mouse, 0);
	mlx_loop(img.mlx);
	return (img);
}