/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:46 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/24 12:47:49 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_take_object(t_mlx_prog *prog)
{
	ft_printf("%d\n", prog->maps->count_obj);
	if (prog->maps->map[prog->pos_player.y][prog->pos_player.x] == 'C')
	{
		ft_put_floor(prog, &prog->sprite);
		prog->maps->count_obj--;
		return (0);
	}
	if (prog->maps->count_obj = 0 && prog->map[prog->pos_player.y][prog->pos_player.x] == 'E')
	{
		write (1, "Well Done", 10);
		exit(0);
	}
	return (0);
}

/*int ft_finish(t_mlx_prog *prog, int count, char **map)
{
	t_position pos;

	if (map[pos.y][pos.x] == 'E')
		ft_put_exit(prog, &prog->sprite);
	if (count = 0 && prog->map[prog->pos_player.y][prog->pos_player.x] == 'E')
	{
		write (1, "Well Done", 10);
		exit(0);
	}
	return (0);
}*/
