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

/*int	ft_put_sprite(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win, s->back_00.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}*/
/*void ft_my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}
*/
int ft_put_wall(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win, s->wall.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int ft_put_floor(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win, s->floor_snow.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int	ft_put_object(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win, s->tree.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int	ft_put_exit(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win, s->wolf_back.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int ft_print_object(t_mlx_prog *p, t_sprite *s, char **map, t_position pos)
{
	if (map[pos.y][pos.x] == 'C')
		ft_put_object(p, s);
	return (0);
}

int ft_print_exit(t_mlx_prog *p, t_sprite *s, char **map, t_position pos)
{
	if (map[pos.y][pos.x] == 'E')
		ft_put_exit(p, s);
	return (0);
}


int	ft_wall_or_floor(t_mlx_prog *p, t_sprite *s, char **map, t_position	pos)
{
	if (map[pos.y][pos.x] == '1')
		ft_put_wall(p, s);
	if (map[pos.y][pos.x] != '1')
		ft_put_floor(p, s);
	return (0);
}