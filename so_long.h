/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:58:50 by cbacquet          #+#    #+#             */
/*   Updated: 2023/06/14 14:54:00 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"

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

typedef struct s_count
{
	int	p;
	int	e;
	int	c;

}	t_count;

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
	t_image		floor_snow;
	t_image		wall;
	t_image		player;
	t_image		exit;
	t_image		mushroom;
	t_position	pos;

}	t_sprite;

typedef struct s_player
{
	t_position	pos;
	t_image		img_player;
	int			dir_x;
	int			dir_y;

}	t_player;

typedef struct s_dir
{
	int	left;
	int	right;
	int	up;
	int	down;

}	t_dir;

typedef struct s_list_img
{
	t_image				*img;
	struct s_list_img	*next;
}	t_list_img;

typedef struct s_mlx_prog
{
	void			*mlx;
	char			**map;
	t_image			img;
	t_window		window;
	t_position		sprite_position;
	t_position		pos_player;
	t_position		pos_object;
	t_dir			dir;
	t_map			*maps;
	t_sprite		sprite;
	t_player		player;
	void			**images_ptr;

}	t_mlx_prog;

typedef struct s_data
{
	void		*mlx;
	t_window	*window;
	t_mlx_prog	*mlx_prog;
}	t_data;

t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path, t_mlx_prog *prog, int i);
t_list_img	*ft_lstnew_img(t_image *content);
void		ft_lstadd_back_img(t_list_img *lst, t_list_img *new);
void		ft_pre_ending(t_mlx_prog *prog);
void		ft_free_img(t_mlx_prog *prog);
int			ft_map_is_rectangle(char **map);
int			ft_map_is_valid(char **maps, int nb_line);
int			ft_count_line(int fd);
char		**ft_fill_map(char **map, int nb_line, int fd);
char		**ft_read_map(t_map *map);
bool		ft_wall_is_ok(char **map, int nb_line);
bool		ft_check_item(t_map *map);
bool		ft_allowed_items(char **map);
int			ft_map_info(t_map *map);
int			ft_way_is_ok(int cpt, int x, int y, t_map *map);
int			ft_close(int keycode, t_data *data);
int			ft_close_mouse(t_data *data);
void		ft_init_map(t_map *map);
int			ft_init_sprite(t_mlx_prog *prog, t_sprite *sprite, t_map *map);


int			ft_game_init(t_map *map);
// bool		ft_game_init(t_map *map);
// int		ft_run_game(t_map *map);

void		ft_free(t_map *map);
int			ft_sprite(t_sprite *sprite, t_mlx_prog *prog);
int			ft_map_start(t_mlx_prog *prog, t_map *map);
int			ft_sprite_map(void *param);
int			ft_sprite_map_object(t_mlx_prog *prog,
				t_sprite *sprite, t_map *map);
int			ft_put_wall(t_mlx_prog *p, t_sprite *s);
int			ft_put_floor(t_mlx_prog *p, t_sprite *s);
int			ft_put_first_exit(t_mlx_prog *p, t_sprite *s);
int			ft_put_exit(t_mlx_prog *prog);
int			ft_print_exit(t_mlx_prog *p,
				t_sprite *s, t_position pos);
int			ft_wall_or_floor(t_mlx_prog *p,
				t_sprite *s, t_position pos);
int			ft_print_object(t_mlx_prog *p,
				t_sprite *s, t_position	pos);
int			ft_print_player(t_mlx_prog *p,
				t_sprite *s, t_position pos);
int			ft_put_object(t_mlx_prog *p, t_sprite *s);
int			ft_put_player(t_mlx_prog *p, t_sprite *s);
int			ft_put_objects(t_mlx_prog *prog);
int			ft_check_right(void *param);
int			ft_check_left(void *param);
int			ft_check_up(void *param);
int			ft_check_down(void *param);
int			ft_check_all(t_mlx_prog *prog);
int			ft_put_wolf(t_mlx_prog *p, t_map *map);
int			ft_move_sprite_player(t_mlx_prog *prog, t_sprite *s, t_map *map);
int			ft_move_up(t_mlx_prog *prog);
int			ft_key_pressed(int key, void *param);
int			ft_key_check(int key, void *param);
int			ft_key_released(int key, void *param);
int			ft_reload_map(void *param);
int			ft_take_object(t_mlx_prog *prog);
int			ft_obj_check(char **map);
int			ft_finish(t_mlx_prog *prog);
int			ft_update_map(t_mlx_prog *prog);
int			ft_init_dir(t_mlx_prog *prog);
void		print_map(char **map);
void		way_is_valid(t_map *map);
void		ft_quit_mlx(t_map *map);
bool		ft_big_map(t_map *map);
void		ft_map_error(int fd);
int			main(int argc, char **argv);

#endif