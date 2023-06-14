/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:29:25 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/14 14:52:45 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

bool	ft_good_ext(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	i -= 3;
	if (ft_strncmp(arg, ".ber", 4) == 0)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_mlx_prog	prog;
	t_data		data;

	ft_bzero(&map, sizeof(t_map));
	if (argc != 2)
	{
		write(1, "Error\nnot valid map\n", 21);
		return (0);
	}
	map.file = argv[1];
	if (!ft_strnstr(map.file, ".ber", ft_strlen(map.file))
		|| ft_good_ext(argv[1]))
	{
		write (2, "Error\nnot valid map\n", 21);
		exit (0);
	}
	ft_bzero(&prog, sizeof(t_mlx_prog));
	ft_bzero(&data, sizeof(t_data));
	ft_init_map(&map);
	ft_game_init(&map);
	ft_run_game(&map);
	return (0);
}
