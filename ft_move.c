/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:06:14 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/13 16:23:06 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_init_dir(t_mlx_prog *prog)
{
	prog->dir.right = 0;
	prog->dir.left = 0;
	prog->dir.up = 0;
	prog->dir.down = 0;
	return (0);
}

int	ft_key_check(int key, void *param)
{
	t_mlx_prog	*p;

	p = (t_mlx_prog *)param;
	if ((key == 100 || key == 65363) && ft_check_right(p) != 0)
	{
		p->pos_player.x += 64;
		p->dir.right = 1;
	}
	if ((key == 119 || key == 65362) && ft_check_up(p) != 0)
	{
		p->pos_player.y += -64;
		p->dir.up = 1;
	}
	if ((key == 115 || key == 65364) && ft_check_down(p) != 0)
	{
		p->pos_player.y += 64;
		p->dir.down = 1;
	}
	if ((key == 97 || key == 65361) && ft_check_left(p) != 0)
	{
		p->pos_player.x += -64;
		p->dir.left = 1;
	}
	return (0);
}

int	ft_key_pressed(int key, void *param)
{
	t_mlx_prog		*p;

	p = (t_mlx_prog *)param;
	if (key == 65307)
	{
		mlx_destroy_image(p->mlx, p->sprite.floor_snow.ref);
		mlx_destroy_image(p->mlx, p->sprite.wall.ref);
		mlx_destroy_image(p->mlx, p->sprite.player.ref);
		mlx_destroy_image(p->mlx, p->sprite.exit.ref);
		mlx_destroy_image(p->mlx, p->sprite.mushroom.ref);
		free(p->images_ptr);
		mlx_destroy_window(p->mlx, p->window.ptr_win);
		mlx_destroy_display(p->mlx);
		free(p->mlx);
		p->mlx = NULL;
		ft_free(p->maps);
		exit(0);
	}
	ft_key_check(key, p);
	return (0);
}

int	ft_check_all(t_mlx_prog *prog)
{
	static int	i;
	static int	x;
	static int	y;

	if (x != prog->pos_player.x || y != prog->pos_player.y)
	{
		ft_printf("\r\033[2K %d", i);
		i++;
		ft_update_map(prog);
		ft_init_dir(prog);
		mlx_put_image_to_window(prog->mlx, prog->window.ptr_win,
			prog->sprite.player.ref, prog->pos_player.x, prog->pos_player.y);
		x = prog->pos_player.x;
		y = prog->pos_player.y;
	}
	return (0);
}
