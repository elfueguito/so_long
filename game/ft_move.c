/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:06:14 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/15 15:06:17 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*int	ft_check_right(void *param)
{
	t_mlx_prog	*prog;
	int 		i;

	prog = (t_mlx_prog *)param;
	i = 0;
	while (i < 29)
	{
		if (prog->map[(prog->player.pos.y + i) / 50][(prog->player.pos.x + 21) / 50] == '1' && prog->player.dir_x == 1)
			return (0);
		if (prog->map[(prog->player.pos.y + i) / 50][(prog->player.pos.x + 10) / 50] == 'C' && prog->player.dir_x == 1)
		{
			prog->map[(prog->player.pos.y + i) / 50][(prog->player.pos.x + 10) / 50] == '0';
			return (1);
		}
		i++;
	}
	return (1);
}

int	ft_check_left(void *param)
{
	t_mlx_prog	*prog;
	int 		i;

	prog = (t_mlx_prog *)param;
	i = 0;
	while (i < 38)
	{
		if (prog->map[(prog->player.pos.y + i) / 50][(prog->player.pos.x - 28) / 50] == '1' && prog->player.dir_x == -1)
			return (0);
		if (prog->map[(prog->player.pos.y + i) / 50][(prog->player.pos.x) / 50] == 'C' && prog->player.dir_x == -1)
		{
			prog->map[(prog->player.pos.y + i) / 50][(prog->player.pos.x) / 50] == '0';
			return (1);
		}
		i++;
	}
	return (1);

}

int ft_check_up(void *param)
{
	t_mlx_prog	*prog;
	int 		i;

	prog = (t_mlx_prog *)param;
	i = 0;
	while (i < 28)
	{
		if (prog->map[(prog->player.pos.y - 3) / 50][(prog->player.pos.x + i) / 50 ] == '1' && prog->player.dir_y == -1)
			return (0);
		if (prog->map[(prog->player.pos.y - 15) / 50][(prog->player.pos.x + i) / 50] == 'C' && prog->player.dir_y == -1)
		{
			prog->map[(prog->player.pos.y - 15) / 50][(prog->player.pos.x + i) / 50] == '0';
			return (1);
		}
		i++;
	}
	return (1);

}

int ft_check_down(void *param)
{
	t_mlx_prog	*prog;
	int			i;

	prog = (t_mlx_prog *)param;
	i = 0;
	while (i < 28)
	{
		if (prog->map[(prog->player.pos.y + 3) / 50][(prog->player.pos.x + i) / 50] == '1' && prog->player.dir_y == 1)
			return (0);
		if (prog->map[(prog->player.pos.y + 15) / 50][(prog->player.pos.x + i) / 50] == 'C' && prog->player.dir_y == 1)
		{
			prog->map[(prog->player.pos.y + 15) / 50][(prog->player.pos.x + i) / 50] == '0';
			return (1);
		}
		i++;
	}
	return (1);
}

int ft_move(int key, void *param)
{
	t_mlx prog	*prog;

	if (key == 100) //go right
		prog->player.pos.x += prog->player.pos.x;
	if (key == 97) //go left
		prog->player.pos.x -= prog->player.pos.x;
	if (key == 115) //go down
		prog->player.pos.y += prog->player.pos.y;
	if (key == 119) //go up
		prog->player.pos.y -= prog->player.pos.y;	
	return (0);
}


int	ft_move_sprite_player(t_mlx_prog *prog, t_sprite *s, t_map *map)
{
	static int	i;

	i = 0;
	if (!ft_check_right(prog))
		prog->player.dir_x = 0;
	if (!ft_check_left(prog))
		prog->player.dir_x = 0;
	if (!ft_check_down(prog))
		prog->player.dir_y = 0;
	if (!ft_check_up(prog))
		prog->player.dir_y = 0;
	else
	{
		prog->player.pos.x += prog->player.dir_x;
		prog->player.pos.y += prog->player.dir_y;
	}
	if (prog->player.dir_x != 0 || prog->player.dir_y != 0)
	{
		i++;
		ft_printf("%d\n", i);
		ft_reload_map(prog, &prog->sprite, map);
		mlx_put_image_to_window(prog->mlx, prog->window.ptr_win, s->player.ref, prog->sprite_position.x, prog->sprite_position.y);
	}

}
*/
int	ft_move_up(int key, t_mlx_prog *prog, t_sprite *s, t_map *map, t_position pos)
{
	//ft_printf("%d\n", key);
	//prog->player_pos.x = ;
	//prog->player_pos.y = ;
	if (key == 119)
	{
		//prog->sprite_position.y -= 50;
		prog->player.pos.y = prog->player.pos.y - 50;
		ft_reload_map(prog, &prog->sprite, map);
		mlx_put_image_to_window(prog->mlx, prog->window.ptr_win, s->player.ref, prog->sprite_position.x, prog->sprite_position.y);
		//ft_printf("x=%d et y=%d\n", prog->player.pos.x, prog->player.pos.y);
		//map->map[pos.y][pos.x] = 'P'; 
		//map->map[(pos.y) + 1][pos.x] = '0';
		ft_printf("reload\n");
		//ft_reload_map(prog, &prog->sprite, map);
		//ft_put_player(prog, s);
		//ft_print_player(prog, s, map->map, pos);
		return (0);	
	}
}


int ft_key_pressed(int key, t_mlx_prog	*prog)
{
	//t_mlx_prog	*prog;

	//prog = (t_mlx_prog *)param;
	if (key == 100) //go right
		return (1);
		//prog->player.dir_x = 1;
	if (key == 97) //go left
		return (1);
		//prog->player.dir_x = -1;
	if (key == 115) //go down
		return (1);
		//prog->player.dir_y = 1;
	if (key == 119) //go up
		return (1);
		//prog->player.dir_y = -1;	
	return (0);
}
/*
int ft_key_released(int key, void * param)
{
	t_mlx_prog	*prog;

	prog = (t_mlx_prog *)param;
	if (key == 100) //go right
		prog->player.dir_x = 0;
	if (key == 97) //go left
		prog->player.dir_x = 0;
	if (key == 115) //go down
		prog->player.dir_y = 0;
	if (key == 119) //go up
		prog->player.dir_y = 0;	
	return (0);
}

*/