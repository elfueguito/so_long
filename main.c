/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:29:25 by cbacquet          #+#    #+#             */
/*   Updated: 2023/03/07 14:45:35 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void print_map(char **map)
{
	int x;
	int y;
	
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int main (int argc, char **argv)
{
	t_map	map;

/*	if (argc == 2)
	{
		write(1, "Map Error", 10);
		return (0);
	}
	map.file = argv[1];*/
	ft_init_map(&map);
	ft_game_init(&map);
	ft_free(map.map);
	return (0);
}