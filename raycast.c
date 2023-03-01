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

void raycast(t_game *game)
{
	int		ray;
	int		wall;
	float	WallHeight;
	float	distance;
	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	rayCos;
	float	raySin;

	ray = 0;
	ray_angle = fix_angle(game->player_angle - FOV2);
	while (ray < (game->width))
	{
		ray_x = game->px;
		ray_y = game->py;
		rayCos = cos(degrees_to_radians(ray_angle));
		raySin = sin(degrees_to_radians(ray_angle));
		wall = 0;
		while (wall == 0)
		{
			ray_x += rayCos;
			ray_y += raySin;
			wall = game->map[(int)ray_y / 16][(int)ray_x / 16];
		}
		distance = distance_between_points(game->px, game->py, ray_x, ray_y);
		distance *= cos(degrees_to_radians(game->player_angle - ray_angle));
		WallHeight = (((game->height * 2)) / distance);
		draw_vertical_line(ray, 0, (game->height / 2) - WallHeight, game, 0x00FFFF);
		draw_vertical_line(ray, (game->height / 2) - WallHeight, (game->height / 2) + WallHeight, game, 0xFF0000);
		draw_vertical_line(ray, (game->height / 2) + WallHeight, game->height, game, 0x00FF00);
		ray_angle = ray_angle + ((float)FOV / (float)(game->width));
		ray++;
	}
}
