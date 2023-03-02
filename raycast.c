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
		draw_walls(cub, ray, ray_angle, ray_x, ray_y);
		ray_angle = (float)(ray_angle + ((float)FOV / (float)(cub->width)));
		ray++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->screen, 0, 0);
}

void draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y)
{
	float	WallHeight;
	float	distance;
	(void)(ray_angle);
	
	distance = distance_between_points(cub->px, cub->py, ray_x, ray_y);
	//distance *= cos(degrees_to_radians(cub->game.player_angle - ray_angle));
	WallHeight = (((cub->height * 2)) / distance);
	if (WallHeight >= cub->height)
		draw_vertical_line(ray, 0, cub->height, cub, 0xFF0000);
	else
	{
		draw_vertical_line(ray, 0, (cub->height / 2) - WallHeight, cub, 0x00FFFF);
		draw_vertical_line(ray, (cub->height / 2) - WallHeight, (cub->height / 2) + WallHeight, cub, 0xFF0000);
		draw_vertical_line(ray, (cub->height / 2) + WallHeight, cub->height, cub, 0x00FF00);
	}
}