/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:53:30 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:06:56 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_right(void *param)
{
	t_mlx_prog	*prog;
	int			x;
	int			y;

	prog = (t_mlx_prog *) param;
	x = prog->pos_player.x / 64;
	y = prog->pos_player.y / 64;
	if ((prog->maps->map[y][x + 1] == '1'))
		return (0);
	if ((prog->maps->map[y][x + 1] == 'C'))
		prog->maps->map[y][x + 1] = '0';
	return (1);
}

int	ft_check_left(void *param)
{
	t_mlx_prog	*prog;
	int			x;
	int			y;

	prog = (t_mlx_prog *) param;
	x = prog->pos_player.x / 64;
	y = prog->pos_player.y / 64;
	if ((prog->maps->map[y][x - 1] == '1'))
		return (0);
	if ((prog->maps->map[y][x - 1] == 'C'))
		prog->maps->map[y][x - 1] = '0';
	return (1);
}

int	ft_check_down(void *param)
{
	t_mlx_prog	*prog;
	int			x;
	int			y;

	prog = (t_mlx_prog *) param;
	x = prog->pos_player.x / 64;
	y = prog->pos_player.y / 64;
	if ((prog->maps->map[y + 1][x] == '1'))
		return (0);
	if ((prog->maps->map[y + 1][x] == 'C'))
		prog->maps->map[y + 1][x] = '0';
	return (1);
}

int	ft_check_up(void *param)
{
	t_mlx_prog	*prog;
	int			x;
	int			y;

	prog = (t_mlx_prog *) param;
	x = prog->pos_player.x / 64;
	y = prog->pos_player.y / 64;
	if ((prog->maps->map[y - 1][x] == '1'))
		return (0);
	if ((prog->maps->map[y - 1][x] == 'C'))
		prog->maps->map[y - 1][x] = '0';
	return (1);
}
