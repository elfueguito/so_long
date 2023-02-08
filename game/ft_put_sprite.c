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

int	ft_put_back(t_mlx_prog *p, t_sprite *s)
{
	mlx_put_image_to_window(p.mlx, p.window.ptr_win, s.back_00.ref, 0, 0);
	return (0);
}