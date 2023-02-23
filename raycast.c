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

void check_horizontal(t_game *game)
{
	game->depht_of_field = 0;
	game->distance_H = 10000;
	game->hx = game->px;
	game->hy = game->py;
	game->aTan = -1 / tan(game->ray_angle);
	if (game->ray_angle > PI)
	{
		game->ray_y = (((int)game->py >> 6) << 6 ) - 0.0001;
		game->ray_x = (game->py - game->ray_y) * game->aTan + game->px;
		game->y_offset = -64;
		game->x_offset = -game->y_offset * game->aTan;
	}
	if (game->ray_angle < PI)
	{
		game->ray_y = (((int)game->py >> 6) << 6 ) + 64;
		game->ray_x = (game->py - game->ray_y) * game->aTan + game->px;
		game->y_offset = 64;
		game->x_offset = -game->y_offset * game->aTan;
	}
	if (game->ray_angle == 0 || game->ray_angle == PI)
	{
		game->ray_x = game->px;
		game->ray_y = game->py;
		game->depht_of_field = 8;
	}
	while (game->depht_of_field < 8)
	{
		game->map_x = (int)(game->ray_x) >> 6;
		game->map_y = (int)(game->ray_y) >> 6;
		game->map_position = game->map_y * game->map_width + game->map_x;
		if (game->map_position > 0 && game->map_position < game->map_width * game->map_height && game->map[game->map_y][game->map_x] == 1)
		{
			game->hx = game->ray_x;
			game->hy = game->ray_y;
			game->distance_H = distance_between_points(game->px, game->py, game->ray_x, game->ray_y);
			game->depht_of_field = 8;
		}
		else
		{
			game->ray_x += game->x_offset;
			game->ray_y += game->y_offset;
			game->depht_of_field += 1;
		}
	}
}

void check_vertical(t_game *game)
{
	game->depht_of_field = 0;
	game->distance_V = 10000;
	game->vx = game->px;
	game->vy = game->py;
	game->nTan = -tan(game->ray_angle);
	if (game->ray_angle > PI2 && game->ray_angle < PI3)
	{
		game->ray_x = (((int)game->px >> 6) << 6 ) - 0.0001;
		game->ray_y = (game->px - game->ray_x) * game->nTan + game->py;
		game->x_offset = -64;
		game->y_offset = -game->x_offset * game->nTan;
	}
	if (game->ray_angle < PI2 || game->ray_angle > PI3)
	{
		game->ray_x = (((int)game->px >> 6) << 6 ) + 64;
		game->ray_y = (game->px - game->ray_x) * game->nTan + game->py;
		game->x_offset = 64;
		game->y_offset = -game->x_offset * game->nTan;
	}
	if (game->ray_angle == 0 || game->ray_angle == PI)
	{
		game->ray_x = game->px;
		game->ray_y = game->py;
		game->depht_of_field = 8;
	}
	while (game->depht_of_field < 8)
	{
		game->map_x = (int)(game->ray_x) >> 6;
		game->map_y = (int)(game->ray_y) >> 6;
		game->map_position = game->map_y * game->map_width + game->map_x;
		if (game->map_position > 0 && game->map_position < game->map_width * game->map_height && game->map[game->map_y][game->map_x] == 1)
		{
			game->vx = game->ray_x;
			game->vy = game->ray_y;
			game->distance_V = distance_between_points(game->px, game->py, game->ray_x, game->ray_y);
			game->depht_of_field = 8;
		}
		else
		{
			game->ray_x += game->x_offset;
			game->ray_y += game->y_offset;
			game->depht_of_field += 1;
		}
	}
}

// Maybe there's a problem with using 64, as the minimap is 32bit
void raycast(t_game *game)
{
	game->ray = 0;
	game->ray_angle = game->player_angle - (RADIAN * 30);
	if (game->ray_angle < 0)
		game->ray_angle += 2 * PI;
	if (game->ray_angle > 2 * PI)
		game->ray_angle -= 2 * PI;
	while(game->ray < 60)
	{
		check_horizontal(game);
		check_vertical(game);
		if (game->distance_H < game->distance_V)
		{
			game->ray_x = game->hx;
			game->ray_y = game->hy;
			game->distance = game->distance_V;
		}
		else
		{
			game->ray_x = game->vx;
			game->ray_y = game->vy;
			game->distance = game->distance_H;
		}
		game->lineH = ((12 * 320) / game->distance);
		if (game->lineH > 320)
			game->lineH = 320;
		game->lineOffset = 160 - (game->lineH / 2);
		draw_vertical_line(game->ray * 8 + 530, game->lineOffset, game->lineH, game, 0x00FF00);
		game->ray_angle += RADIAN;	
		if (game->ray_angle < 0)
			game->ray_angle += 2 * PI;
		if (game->ray_angle > 2 * PI)
			game->ray_angle -= 2 * PI;
		game->ray++;
	}
}