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
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"

# include <stdio.h>

typedef struct s_map
{
	char	*file;
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


typedef struct s_position
{
	int	x;
	int	y;

}	t_position;


typedef struct s_image
{
	void		*ref;
	void		*addr;
	int			bits_per_pixels;
	int			line_length;
	int			endian;
	t_position	size;

}	t_image;


typedef struct s_window
{
	void		*ptr_win;
	t_position	size;

}	t_window;

typedef struct s_sprite
{
	t_image		back_00;
	t_position	pos;

}	t_sprite;

typedef struct s_mlx_prog
{
	void		*mlx;
	char		**map;
	t_image		img;
	t_window	window;
	t_position	sprite_position;
	t_sprite	sprite;

}	t_mlx_prog;


t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);

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
int		ft_way_is_ok(int cpt, int x, int y, t_map *map);
int 	ft_close(int keycode, t_mlx_prog *window);
int		ft_close_mouse(void);
void    ft_init_map(t_map *map);
int		ft_game_init(t_map *map);
void    *ft_free(char **map);
int		ft_sprite_back(t_sprite *sprite, t_mlx_prog *prog);
int		ft_map_start(t_mlx_prog *prog, t_map *map);
int		main(int argc, char **argv);

# endif