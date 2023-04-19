/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:23:09 by marvin            #+#    #+#             */
/*   Updated: 2023/04/18 23:23:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_hit(t_cub *cub, float ray_x, float ray_y);

void	get_wall_direction(int x, int y, double len, t_cub *cub, double wall_x, double ray_x, double ray_y)
{
	if (cub->game.vertical)
	{
		if (ray_x < cub->px)
			draw_texture(x, y, len, cub, wall_x, cub->img.we_tex);
		else
			draw_texture(x, y, len, cub, wall_x, cub->img.ea_tex);
	}
	else
	{
		if (ray_y < cub->py)
			draw_texture(x, y, len, cub, wall_x, cub->img.no_tex);
		else
			draw_texture(x, y, len, cub, wall_x, cub->img.so_tex);
	}
}

void	draw_texture(int x, int y, double len, t_cub *cub, double wall_x, t_img *texture)
{
	int		i;
	double	tex_y;
	double	increment;

	increment = texture->height / len;
	i = 0;
	tex_y = 0;
	while (i < len && i < cub->height)
	{
		if (y < cub->height && x < cub->width && (y >= 0 && x >= 0 && tex_y <= texture->height && wall_x <= texture->width))
			my_mlx_pixel_put(cub, x, y,
			my_mlx_pixel_get(texture, floor(wall_x), floor(tex_y)));
		tex_y += increment;
		y++;
		i++;
	}
}
