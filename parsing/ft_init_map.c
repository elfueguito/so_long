/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:58:28 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:17:55 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map(t_map *map)
{
	ft_read_map(map);
	ft_map_info(map);
	ft_way_is_ok(map->count_obj, map->start_x, map->start_y, map);
	ft_free(map->map);
	ft_read_map(map);
	ft_map_info(map);
}
