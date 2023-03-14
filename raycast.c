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
	float	increment;

	ray = 0;
	clear_fov(cub);
	ray_angle = fix_angle(cub->game.player_angle - FOV2);
	increment = (float)FOV / (float)cub->width;
	while (ray < (cub->width))
	{
		ray_x = cub->px;
		ray_y = cub->py;
		rayCos = cos(degrees_to_radians(ray_angle)) / 20;
		raySin = sin(degrees_to_radians(ray_angle)) / 20;
		wall = '0';
		while (wall == '0')
		{
			ray_x += rayCos;
			ray_y += raySin;
			draw_fov(cub, ray_x + 2, ray_y + 2, 0x0000FF00);
			wall = cub->map.map[(int)(ray_y / 16)][(int)(ray_x / 16)];
		}
		draw_walls(cub, ray, ray_angle, ray_x, ray_y);
		ray_angle += increment;
		ray++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen, 0, 0);
}

void draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y)
{
	float	WallHeight;
	float	distance;
	float	new_distance;
	int 	PerpWallDist;
	float	WallX;

	distance = distance_between_points(cub->px, cub->py, ray_x, ray_y);
	new_distance = distance * cos(degrees_to_radians(ray_angle - cub->game.player_angle));
	PerpWallDist = sqrt(pow(new_distance, 2) - pow(cub->py - ray_y, 2));
	WallHeight = floor((cub->height * 2) / new_distance);
	WallX = cub->px + PerpWallDist * cos(degrees_to_radians(ray_angle));
	WallX -= floor(WallX);
	if (WallHeight >= cub->height)
	{
		if (cub->game.textures_on == 1)
			draw_texture(ray, 0, cub->height, cub, WallX, ray_x);
		else
			draw_vertical_line(ray, 0, cub->height, cub, 0xFF0000);
	}
	else
	{
		if (cub->game.lights == 1)
		{
			draw_vertical_line(ray, 0, floor((cub->height / 2) - WallHeight), cub, cub->img.colors[1]);
			if (cub->game.textures_on == 1)
				draw_texture(ray, floor((cub->height / 2) - WallHeight), 2 * WallHeight, cub, WallX, ray_x);
			else
				draw_vertical_line(ray, floor((cub->height / 2) - WallHeight), 2 * WallHeight, cub, 0xFF0000);
			draw_vertical_line(ray, floor((cub->height / 2) + WallHeight), cub->height, cub, cub->img.colors[0]);
		}
		else if (cub->game.lights == 0)
		{
			draw_vertical_line(ray, 0, floor((cub->height / 2) - WallHeight), cub, 0x00000000);
			if (cub->game.textures_on == 1)
				draw_texture(ray, floor((cub->height / 2) - WallHeight), 2 * WallHeight, cub, WallX, ray_x);
			else
				draw_vertical_line(ray, floor((cub->height / 2) - WallHeight), 2 * WallHeight, cub, 0xFF0000);
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

void	draw_texture(int x, int y, float len, t_cub *cub, float WallX, float ray_x)
{
	draw_texture2(x, y, len, cub, WallX, cub->img.NO_tex, ray_x);
	/*
	if ((int)ray_y % 16 == 0)
	{
		if (ray_y < 0)
			draw_texture2(x, y, len, cub, WallX, cub->img.NO_tex);
		else
			draw_texture2(x, y, len, cub, WallX, cub->img.SO_tex);
	}
	else
	{
		if (ray_x < 0)
			draw_texture2(x, y, len, cub, WallX, cub->img.WE_tex);
		else
			draw_texture2(x, y, len, cub, WallX, cub->img.EA_tex);
	}
	*/
}

void	draw_texture2(int x, int y, float len, t_cub *cub, float WallX, t_img_mlx *texture, float ray_x)
{
	int 	i;
	float	tex_x;
	int		texX;
	float	tex_y;
	float	increment;

	(void)(ray_x);
	texX = (int)(WallX * (float)texture->width);
	if (ray_x < 0)
		tex_x = texture->width - texX;
	else
		tex_x = texX;
	//tex_x = texture->width - tex_x - 1;
	increment = texture->height / len;
	i = 0;
	tex_y = 0;
	while (i < len && i < cub->height)
	{
		if (y < cub->height && x < cub->width && (y >= 0 && x >= 0 && tex_y <= texture->height && tex_x <= texture->width))
			my_mlx_pixel_put(cub, x, y, 
			my_mlx_pixel_get(texture, tex_x, tex_y));
		tex_y += increment;
		y++;
		i++;
	}
}
