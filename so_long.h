/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:58:50 by cbacquet          #+#    #+#             */
/*   Updated: 2023/01/30 14:47:18 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

typedef struct s_map
{
	char	**map;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		count_obj;
	int		f_count;
	int		height;
	int		width;
	
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
	char	*name;
}	t_data;

typedef struct s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

int		ft_map_is_rectangle(char **map);
int		ft_map_is_valid(char **map, int nb_line);
int 	ft_count_line(int fd);
char	**ft_fill_map(char **map, int nb_line, int fd);
char	**ft_read_map(t_map *map);
int		ft_wall_up(char **map);
int		ft_wall_down(char **map, int nb_line);
int		ft_wall_left(char **map);
int		ft_wall_right(char **map);
int		ft_wall_is_ok(char **map, int nb_line);
int		ft_check_enter(char **map);
int		ft_check_exit(char **map);
int		ft_check_objects(char **map);
int		ft_check_item(char **map);
int		ft_map_info(t_map *map);
int		ft_count_obj(char **map);
int		ft_P_x(char **map);
int		ft_P_y(char **map);
int		ft_E_x(char **map);
int		ft_E_y(char **map);
int		ft_move_to_check(int cpt, int x, int y, t_map *map);
int		ft_check_up(int x, int y, t_map *map);
int		ft_check_down(int x, int y, t_map *map);
int		ft_check_left(int x, int y, t_map *map);
int		ft_check_right(int x, int y, t_map *map);
int 	ft_close(int keycode, t_data *img);
int		ft_close_mouse(void);

# endif