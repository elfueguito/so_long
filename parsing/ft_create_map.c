/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:43 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/30 14:41:00 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_is_rectangle(char **map)
{
	int	i;
	
	i = 0;
	while (map [i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int ft_map_is_valid(char **map, int nb_line)
{
//	int i;
	
//	i = 0;
	if (ft_map_is_rectangle(map))
		if (ft_wall_is_ok(map, nb_line))
			return (1);
	return (0);
}

int	ft_count_line(int fd)
{
	char	c;
	int		count;
		
	count = 0;
	while (read(fd, &c, 1 > 0))
	{
		if(c == '\n')	
			count++;
	}
	return(count);
}

char	**ft_fill_map(char **map, int nb_line, int fd)
{
	int i;
	
	i = 0;
	map = malloc(sizeof(char *) * nb_line + 1);
	if(!map)
		return (free(map), NULL);
	map[nb_line] = NULL;
	while(nb_line > 0)
	{
		map[i] = get_next_line(fd);
		nb_line--;
		i++;
	}
	return(map);
}

char	**ft_read_map(t_map *map)
{
	int		fd;
	
	fd = open("maps/map_basic.ber", O_RDONLY);
	map->height = ft_count_line(fd);
	
	close (fd);
	fd = open("maps/map_basic.ber", O_RDONLY);
	map->map = ft_fill_map(map->map, map->height, fd);
	close(fd);
	ft_map_is_valid(map->map, map->height);
	ft_printf("\nmap valide : %d \n", ft_map_is_valid(map->map, map->height));
	ft_check_item(map->map);
	ft_printf("\nitems OK : %d\n\n", ft_check_item(map->map));
	
	return (0);
}

/*
int main (void)
{	
	int 		b;
	//int 		fd;
	t_map		map;

	b = 0;
	ft_read_map(&map);
	ft_map_info(&map);
	ft_printf("nombre objets : %d\n\n", map.count_obj);
	while (map.map[b])
		ft_printf("%s\n", map.map[b++]);
	ft_printf("\n");
	b = 0;
	map.f_count = 0;
	if (!ft_move_to_check(map.count_obj + 1, map.start_x, map.start_y, &map))
	{
		ft_printf("error chemin");
		return(0);
	}
	while (map.map[b])
		ft_printf("%s\n", map.map[b++]);
	free(map.map);
	return (0);
}
*/