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

void	get_wall_direction(int x, int y, float len, t_cub *cub, float wall_x, float ray_x, float ray_y)
{
	if (check_hit(cub, ray_x, ray_y))
	{
		if (ray_x < cub->px)
			draw_texture(x, y, len, cub, wall_x, cub->img.WE_tex);
		else
			draw_texture(x, y, len, cub, wall_x, cub->img.EA_tex);
	}
	else
	{
		if (ray_y < cub->py)
			draw_texture(x, y, len, cub, wall_x, cub->img.NO_tex);
		else
			draw_texture(x, y, len, cub, wall_x, cub->img.SO_tex);
	}
}

void	draw_texture(int x, int y, float len, t_cub *cub, float wall_x, t_img_mlx *texture)
{
	int 	i;
	float	tex_y;
	float	increment;

	increment = texture->height / len;
	i = 0;
	tex_y = 0;
	while (i < len && i < cub->height)
	{
		if (y < cub->height && x < cub->width && (y >= 0 && x >= 0 && tex_y <= texture->height && wall_x <= texture->width))
			my_mlx_pixel_put(cub, x, y,
			my_mlx_pixel_get(texture, (int)wall_x, (int)tex_y));
		tex_y += increment;
		y++;
		i++;
	}
}
