/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:53:56 by cbacquet          #+#    #+#             */
/*   Updated: 2023/02/08 12:53:59 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int ft_sprite_back(t_sprite *sprite, t_mlx_prog *prog)
{
    sprite->back_00 = ft_new_sprite(prog->mlx, "space_background/preview.xpm");
    return (0);
}


t_image ft_new_sprite(void *mlx, char *path)
{
    t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
    img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixels, &img.line_length, &img.endian);
    return (img);
}
