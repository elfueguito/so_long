/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:54:46 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:03:22 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_wall(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win,
		s->wall.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int	ft_put_floor(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win,
		s->floor_snow.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int	ft_put_object(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win,
		s->mushroom.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int	ft_put_first_exit(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win,
		s->exit.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}

int	ft_put_player(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p->mlx, p->window.ptr_win,
		s->player.ref, p->sprite_position.x, p->sprite_position.y);
	return (0);
}
