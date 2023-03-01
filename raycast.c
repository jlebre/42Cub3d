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
	float	WallHeight;
	float	distance;
	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	rayCos;
	float	raySin;

	ray = 0;
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
			wall = cub->map.map[(int)ray_y / 16][(int)ray_x / 16];
			//printf("map[%d][%d] = %c\n", (int)ray_y / 16, (int)ray_x / 16, wall);
		}
		distance = distance_between_points(cub->px, cub->py, ray_x, ray_y);
		distance *= cos(degrees_to_radians(cub->game.player_angle - ray_angle));
		WallHeight = (((cub->height * 2)) / distance);
		draw_vertical_line(ray, 0, (cub->height / 2) - WallHeight, cub, 0x00FFFF);
		draw_vertical_line(ray, (cub->height / 2) - WallHeight, (cub->height / 2) + WallHeight, cub, 0xFF0000);
		draw_vertical_line(ray, (cub->height / 2) + WallHeight, cub->height, cub, 0x00FF00);
		ray_angle = ray_angle + ((float)FOV / (float)(cub->width));
		ray++;
	}
}
