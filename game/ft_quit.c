/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:07:25 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/30 14:17:58 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_close(int keycode, t_mlx_prog *window)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(window->mlx, window->window.ptr_win);
		exit (0);
	}
	printf("%d\n", keycode);
	return (0);
}

int ft_close_mouse(void)
{
	exit(0);
}

t_window ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	window;
	t_image		img;

	window.ptr_win = mlx_new_window(mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.ptr_win, 2, 1L<<0, ft_close, &img.ref);
	mlx_hook(window.ptr_win, 17, 0, ft_close_mouse, 0);
	return (window);
}