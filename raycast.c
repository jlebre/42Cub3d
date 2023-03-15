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
	float	cameraX;
	float	deltaDistX;
	float	deltaDistY;
	int 	hit;
	int 	side;

	ray = 0;
	hit = 0;
	//clear_fov(cub);
	cub->proj.ra = fix_angle(cub->game.pa - FOV2);
	cub->proj.increment = (float)FOV / (float)cub->width;
	while (ray < (cub->width))
	{
		cameraX = 2 * ray / (float)cub->width - 1;
		cub->proj.rayDirX = cub->dx + cub->proj.planeX * cameraX;
		cub->proj.rayDirY = cub->dy + cub->proj.planeY * cameraX;
		cub->proj.mapX = (int)cub->px;
		cub->proj.mapY = (int)cub->py;
		if (cub->proj.rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = ft_abs(1 / cub->proj.rayDirX);
		if (cub->proj.rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = ft_abs(1 / cub->proj.rayDirY);
		cub->proj.stepX = 1 - (2 * (cub->proj.rayDirX < 0));
		if (cub->proj.rayDirX < 0)
			cub->proj.ray_x = (cub->px - cub->proj.mapX) * deltaDistX;
		else
			cub->proj.ray_x = (cub->proj.mapX + 1.0 - cub->px) * deltaDistX;
		cub->proj.stepY = 1 - (2 * (cub->proj.rayDirY < 0));
		if (cub->proj.rayDirY < 0)
			cub->proj.ray_y = (cub->py - cub->proj.mapY) * deltaDistY;
		else
			cub->proj.ray_y = (cub->proj.mapY + 1.0 - cub->py) * deltaDistY;
		while (hit == 0)
		{
			if (cub->proj.ray_x < cub->proj.ray_y)
			{
				cub->proj.ray_x += deltaDistX;
				cub->proj.mapX += cub->proj.stepX;
				side = 0;
			}
			else
			{
				cub->proj.ray_y += deltaDistY;
				cub->proj.mapY += cub->proj.stepY;
				side = 1;
			}
			if (cub->map.map[cub->proj.mapY / 16][cub->proj.mapX / 16] == '1')
				hit = 1;
		}
		if (side == 0)
			cub->proj.PerpWallDist = cub->proj.ray_x - deltaDistX;
		else
			cub->proj.PerpWallDist = cub->proj.ray_y - deltaDistY;
		printf("ray_x: %f, ray_y: %f, deltaDistX: %f, deltaDistY: %f\n", cub->proj.ray_x, cub->proj.ray_y, deltaDistX, deltaDistY);
		printf("PerpWallDist: %f\n", cub->proj.PerpWallDist);
		//draw_fov(cub, cub->proj.ray_x + 2, cub->proj.ray_y + 2, 0x0000FF00);
		draw_walls(cub, ray);
		cub->proj.ra += cub->proj.increment;
		ray++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen, 0, 0);
}

void draw_walls(t_cub *cub, int ray)
{
	float	tex_start;

	cub->proj.distance = dist(cub->px, cub->py, cub->proj.ray_x, cub->proj.ray_y);
	cub->proj.new_distance = cub->proj.distance * cos(dtr(cub->proj.ra - cub->game.pa));
	cub->proj.PerpWallDist = sqrt(pow(cub->proj.new_distance, 2) - pow(cub->py - cub->proj.ray_y, 2));
	cub->proj.WallHeight = (int)(cub->height / cub->proj.PerpWallDist);
	if (cub->proj.ray_x > cub->proj.ray_y)
		cub->proj.WallX = cub->py + cub->proj.PerpWallDist * sin(dtr(cub->proj.ra));
	else
		cub->proj.WallX = cub->px + cub->proj.PerpWallDist * cos(dtr(cub->proj.ra));
	cub->proj.WallX -= floor(cub->proj.WallX);
	tex_start = floor((cub->height / 2) - cub->proj.WallHeight);
	if (cub->proj.WallHeight >= cub->height)
	{
		if (cub->game.textures_on == 1)
			draw_texture(ray, 0, cub->height, cub);
		else
			draw_vertical_line(ray, 0, cub->height, cub, 0xFF0000);
	}
	else
		draw_walls2(cub, ray, tex_start);
}

void	draw_walls2(t_cub *cub, int ray, float tex_start)
{
	int	draw_start;
	int	draw_end;

	(void)tex_start;
	draw_start = (-cub->proj.WallHeight / 2) + (cub->height / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (cub->proj.WallHeight / 2) + (cub->height / 2);
	if (draw_end >= cub->height)
		draw_end = cub->height - 1;
	//printf("WallHeight: %d, cub->height: %d\n", cub->proj.WallHeight, cub->height);
	//printf("draw_start: %d, draw_end: %d\n", draw_start, draw_end);
	draw_vertical_line(ray, 0, draw_start, cub, cub->img.colors[1]);
	draw_vertical_line(ray, draw_start, draw_end, cub, 0xFF0000);
	draw_vertical_line(ray, draw_end, cub->height, cub, cub->img.colors[0]);
	/* if (cub->game.textures_on == 1)
		draw_texture(ray, tex_start, 2 * cub->proj.WallHeight, cub);
	else */
}

/*
void	draw_walls2(t_cub *cub, int ray, float tex_start)
{
	if (cub->game.lights == 1)
	{
		draw_vertical_line(ray, 0, tex_start, cub, cub->img.colors[1]);
		if (cub->game.textures_on == 1)
			draw_texture(ray, tex_start, 2 * cub->proj.WallHeight, cub);
		else
			draw_vertical_line(ray, tex_start, 2 * cub->proj.WallHeight, cub, 0xFF0000);
		draw_vertical_line(ray, floor((cub->height / 2) + cub->proj.WallHeight), cub->height, cub, cub->img.colors[0]);
	}
	else if (cub->game.lights == 0)
	{
		draw_vertical_line(ray, 0, tex_start, cub, 0x00000000);
		if (cub->game.textures_on == 1)
			draw_texture(ray, tex_start, 2 * cub->proj.WallHeight, cub);
		else
			draw_vertical_line(ray, tex_start, 2 * cub->proj.WallHeight, cub, 0xFF0000);
		draw_vertical_line(ray, floor((cub->height / 2) + cub->proj.WallHeight), cub->height, cub, 0x00000000);
	}
	cub->proj.mapX = (int)cub->proj.ray_x / 16;
	cub->proj.mapY = (int)cub->proj.ray_y / 16;
	//printf("mapX: %d, mapY: %d\n", cub->proj.mapX, cub->proj.mapY);
}
*/

int	round_down(float num)
{
	int		integer;

	integer = (int)num;
	if (num < 0)
		integer--;
	return (integer);
}

void	draw_texture(int x, int y, float len, t_cub *cub)
{
	draw_texture2(x, y, len, cub, cub->img.chess);
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

void	draw_texture2(int x, int y, float len, t_cub *cub, t_img_mlx *texture)
{
	int 	i;
	float	tex_x;
	int		texX;
	float	tex_y;
	float	increment;

	texX = (int)(cub->proj.WallX * (float)texture->width);
	if (cub->proj.ray_x > cub->proj.ray_y)
	{
		if (cub->proj.ray_y < 0)
			tex_x = texture->width - texX - 1;
		else
			tex_x = texX;
	}
	else
	{
		if (cub->proj.ray_x < 0)
			tex_x = texture->width - texX - 1;
		else
			tex_x = texX;
	}
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
