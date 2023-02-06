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

int	ft_quit(void)
{
	t_data	img;
	
	img.mlx = mlx_init();
	//img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Welcome in the game !");
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.mlx_win, 17, 0, ft_close_mouse, 0);
	mlx_loop(img.mlx);
	return (0);
}