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

void	get_wall_direction(int y, double len, t_cub *cub)
{
	if (cub->ray.vertical)
	{
		if (cub->ray.ray_x < cub->px)
			draw_texture(y, len, cub, cub->img.we_tex);
		else
			draw_texture(y, len, cub, cub->img.ea_tex);
	}
	else
	{
		if (cub->ray.ray_y < cub->py)
			draw_texture(y, len, cub, cub->img.no_tex);
		else
			draw_texture(y, len, cub, cub->img.so_tex);
	}
}

void	draw_texture(int y, double len, t_cub *cub, t_img *texture)
{
	int		i;
	double	tex_y;
	double	increment;

	increment = texture->height / len;
	i = 0;
	tex_y = 0;
	while (i < len && i < cub->height)
	{
		if (y < cub->height && cub->ray.ray < cub->width
			&& (y >= 0 && cub->ray.ray >= 0 && tex_y <= texture->height
				&& cub->ray.wall_x <= texture->width))
			my_mlx_pixel_put(cub, cub->ray.ray, y, my_mlx_pixel_get(texture,
					cub->ray.wall_x, tex_y));
		tex_y += increment;
		y++;
		i++;
	}
}
