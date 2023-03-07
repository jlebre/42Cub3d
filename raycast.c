/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:30:54 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 16:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(t_cub *cub)
{
	int		ray;
	char	wall;
	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	rayCos;
	float	raySin;

	ray = 0;
	clear_fov(cub);
	ray_angle = fix_angle(cub->game.player_angle - FOV2);
	while (ray < (cub->width))
	{
		ray_x = cub->px;
		ray_y = cub->py;
		rayCos = cos(degrees_to_radians(ray_angle));
		raySin = sin(degrees_to_radians(ray_angle));
		wall = '0';
		while (wall == '0')
		{
			ray_x += rayCos;
			ray_y += raySin;
			draw_fov(cub, ray_x + 2, ray_y + 2, 0x0000FF00);
			wall = cub->map.map[(int)ray_y / 16][(int)ray_x / 16];
		}
		draw_walls(cub, ray, ray_angle, floor(ray_x), floor(ray_y));
		ray_angle += ((float)FOV / (float)(cub->width));
		ray++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen, 0, 0);
}

void draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y)
{
	float	WallHeight;
	float	distance;
	float	new_distance;
	float	new_angle;
	(void)(ray_angle);
	
	distance = distance_between_points(cub->px, cub->py, ray_x, ray_y);
	new_angle = fix_angle(ray_angle - cub->game.player_angle);
	new_distance = distance * cos(degrees_to_radians(new_angle));
	WallHeight = floor((cub->height * 2) / new_distance);
	if (WallHeight >= cub->height)
	{
		if (cub->game.textures_on == 1)
			draw_texture(ray, 0, cub->height, cub, ray_x, ray_y);
		else
			draw_vertical_line(ray, 0, cub->height, cub, 0xFF0000);
	}
	else
	{
		if (cub->game.lights == 1)
		{
			draw_vertical_line(ray, 0, floor((cub->height / 2) - WallHeight), cub, cub->img.colors[1]);
			if (cub->game.textures_on == 1)
				draw_texture(ray, floor((cub->height / 2) - WallHeight), floor(cub->height / 2) + WallHeight, cub, ray_x, ray_y);
			else
				draw_vertical_line(ray, floor((cub->height / 2) - WallHeight), floor(cub->height / 2) + WallHeight, cub, 0xFF0000);
			draw_vertical_line(ray, floor((cub->height / 2) + WallHeight), cub->height, cub, cub->img.colors[0]);
		}
		else if (cub->game.lights == 0)
		{
			draw_vertical_line(ray, 0, floor((cub->height / 2) - WallHeight), cub, 0x00000000);
			if (cub->game.textures_on == 1)
				draw_texture(ray, floor((cub->height / 2) - WallHeight), floor(cub->height / 2) + WallHeight, cub, ray_x, ray_y);
			else
				draw_vertical_line(ray, floor((cub->height / 2) - WallHeight), floor(cub->height / 2) + WallHeight, cub, 0xFF0000);
			draw_vertical_line(ray, floor((cub->height / 2) + WallHeight), cub->height, cub, 0x00000000);
		}
	}
}

int	round_down(float num)
{
	int		integer;

	integer = (int)num;
	if (num < 0)
		integer--;
	return (integer);
}

void	draw_texture(int x, int y, float len, t_cub *cub, float ray_x, float ray_y)
{
	float	tex_x;
	float	tex_y;
	char	*tex;
	float	increment;

	(void)(ray_y);
	(void)(ray_x);
	tex_x = (cub->img.chess->width / (cub->width / (float)x));
	increment = cub->img.chess->height / len;
	len += y;
	tex_y = 0;
	while (y < len && y < cub->height)
	{
		//dst = cub->screen->data + (y * cub->screen->size_line + x * (cub->screen->bpp / 8));
		tex = cub->img.chess->data + ((round_down)(tex_y) * cub->img.chess->size_line) + ((round_down)(tex_x) * (cub->img.chess->bpp / 8));
		if (y < cub->height && x < cub->width && (y >= 0 && x >= 0 && tex_y <= cub->img.chess->height && tex_x <= cub->img.chess->width))
			my_mlx_pixel_put(cub, x, y, *(unsigned int *)tex);
		tex_y += increment;
		y++;
	}
}
