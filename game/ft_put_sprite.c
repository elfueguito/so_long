/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:54:46 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/08 12:54:48 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_sprite(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p.mlx, p.window.ptr_win, s.back_00.ref, 0, 0);
	return (0);
}

int ft_put_wall(t_mlx_prog *p, t_sprite *s, char **map, t_mlx_prog *prog)
{
	if (map[pos.y][pos.x] == '1')
		mlx_put_image_to_window(p.mlx, p.window.ptr_win, s.wall.ref, 0, 0);
	return (0);
}

int ft_put_floor(t_mlx_prog *p, t_sprite *s, char **map, t_mlx_prog *prog)
{
	if (map[pos.y][pos.x] == '0')
		mlx_put_image_to_window(p.mlx, p.window.ptr_win, s.floor_snow.ref, 0, 0);
	return (0);
}