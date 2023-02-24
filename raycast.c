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

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void check_vertical(t_game *game)
{
	int dof;
	float Tan;

	dof = 0;
	game->distance_V = 10000;
	Tan = tan(degrees_to_radians(game->ray_angle));
	if (cos(degrees_to_radians(game->ray_angle)) > 0.001)
	{
		game->ray_x = (((int)game->px >> 6) << 6 ) + 64;
		game->ray_y = (game->px - game->ray_x) * Tan + game->py;
		game->x_offset = 64;
		game->y_offset = -game->x_offset * Tan;
	}
	else if (cos(degrees_to_radians(game->ray_angle)) < -0.001)
	{
		game->ray_x = (((int)game->px >> 6) << 6 ) - 0.0001;
		game->ray_y = (game->px - game->ray_x) * Tan + game->py;
		game->x_offset = -64;
		game->y_offset = -game->x_offset * Tan;
	}
	else
	{
		game->ray_x = game->px;
		game->ray_y = game->py;
		dof = 8;
	}
	while (dof < 8)
	{
		game->map_x = (int)(game->ray_x) >> 6;
		game->map_y = (int)(game->ray_y) >> 6;
		game->map_position = game->map_y * game->map_width + game->map_x;
		if (game->map_position > 0 && game->map_position < game->map_width * game->map_height && game->map[game->map_y][game->map_x] == 1)
		{
			dof = 8;
			game->distance_V = cos(degrees_to_radians(game->ray_angle)) * (game->ray_x - game->px) - sin(degrees_to_radians(game->ray_angle)) * (game->ray_y - game->py);
		}
		else
		{
			game->ray_x += game->x_offset;
			game->ray_y += game->y_offset;
			dof += 1;
		}
		game->vx = game->ray_x;
		game->vy = game->ray_y;
	}
}

void check_horizontal(t_game *game)
{
	int dof;
	float aTan;

	dof = 0;
	game->distance_H = 10000;
	aTan = 1 / tan(degrees_to_radians(game->ray_angle));
	if (sin(degrees_to_radians(game->ray_angle)) > 0.001)
	{
		game->ray_y = (((int)game->py >> 6) << 6 ) - 0.0001;
		game->ray_x = (game->py - game->ray_y) * aTan + game->px;
		game->y_offset = -64;
		game->x_offset = -game->y_offset * aTan;
	}
	else if (sin(degrees_to_radians(game->ray_angle)) < -0.001)
	{
		game->ray_y = (((int)game->py >> 6) << 6 ) + 64;
		game->ray_x = (game->py - game->ray_y) * aTan + game->px;
		game->y_offset = 64;
		game->x_offset = -game->y_offset * aTan;
	}
	else
	{
		game->ray_x = game->px;
		game->ray_y = game->py;
		dof = 8;
	}
	while (dof < 8)
	{
		game->map_x = (int)(game->ray_x) >> 6;
		game->map_y = (int)(game->ray_y) >> 6;
		game->map_position = game->map_y * game->map_width + game->map_x;
		if (game->map_position > 0 && game->map_position < game->map_width * game->map_height && game->map[game->map_y][game->map_x] == 1)
		{
			dof = 8;
			game->distance_H = cos(degrees_to_radians(game->ray_angle)) * (game->ray_x - game->px) - sin(degrees_to_radians(game->ray_angle)) * (game->ray_y - game->py);
		}
		else
		{
			game->ray_x += game->x_offset;
			game->ray_y += game->y_offset;
			dof += 1;
		}
	}
}

void raycast(t_game *game)
{
	int ray;
	int	ca;
	
	ray = 0;
	printf("ray_angle %f\n", game->ray_angle);
	printf("player_angle %f\n", game->player_angle);
	game->ray_angle = fix_angle(game->player_angle + 30);
	while(ray < 60)
	{
		printf("ray_angle %f\n", game->ray_angle);
		printf("ray %d\n", ray);
		check_vertical(game);
		printf("vertical\n");
		check_horizontal(game);
		printf("horizontal\n");
		if (game->distance_V < game->distance_H)
		{
			game->ray_x = game->vx;
			game->ray_y = game->vy;
			game->distance_H = game->distance_V;
		}
		ca = fix_angle(game->player_angle - game->ray_angle);
		game->distance_H = game->distance_H * cos(degrees_to_radians(ca));
		game->lineH = ((64 * 320) / game->distance_H);
		if (game->lineH > 320)
			game->lineH = 320;
		game->lineOffset = 160 - (game->lineH >> 1);
		draw_vertical_line(ray * 8 + 530, game->lineOffset, game->lineH, game, 0x00FFF0);
		//draw_wall(game->ray * 8 + 530, game->lineOffset, fix_angle(game->ray_angle), game->lineH, game);
		game->ray_angle = fix_angle(game->ray_angle - 1);
		ray++;
	}
}