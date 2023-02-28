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

int	get_ray_pos(float p)
{
	int ray_pos;

	ray_pos = ((int)p / 64) * 64;
	return (ray_pos);
}
/* 
// Check Vertical Hit
void check_vertical(float ray_angle, t_game *game)
{
	int dof;
	float Tan;

	dof = 0;
	game->distance_V = 10000;
	Tan = tan(degrees_to_radians(ray_angle));
	if (cos(degrees_to_radians(ray_angle)) > 0.001)
	{
		game->ray_x = get_ray_pos(game->px) + 64;
		game->ray_y = (game->px - game->ray_x) * Tan + game->py;
		game->x_offset = 64;
		game->y_offset = -game->x_offset * Tan;
	}
	else if (cos(degrees_to_radians(ray_angle)) < -0.001)
	{
		game->ray_x = get_ray_pos(game->px) - 0.0001;
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
		game->map_x = game->ray_x / 64;
		game->map_y = game->ray_y / 64;
		game->map_position = game->map_y * game->map_width + game->map_x;
		if (game->map_position > 0 && game->map_position < game->map_width * game->map_height && game->map[game->map_y][game->map_x] == 1)
		{
			dof = 8;
			game->distance_V = cos(degrees_to_radians(ray_angle)) * (game->ray_x - game->px) - sin(degrees_to_radians(ray_angle)) * (game->ray_y - game->py);
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

// Check Horizontal Hit
void check_horizontal(float ray_angle, t_game *game)
{
	int dof;
	float aTan;

	dof = 0;
	game->distance_H = 10000;
	aTan = 1 / tan(degrees_to_radians(ray_angle));
	if (sin(degrees_to_radians(ray_angle)) > 0.001)
	{
		game->ray_y = get_ray_pos(game->py) - 0.0001;
		game->ray_x = (game->py - game->ray_y) * aTan + game->px;
		game->y_offset = -64;
		game->x_offset = -game->y_offset * aTan;
	}
	else if (sin(degrees_to_radians(ray_angle)) < -0.001)
	{
		game->ray_y = get_ray_pos(game->py) + 64;
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
		game->map_x = game->ray_x / 64;
		game->map_y = game->ray_y / 64;
		game->map_position = game->map_y * game->map_width + game->map_x;
		if (game->map_position > 0 && game->map_position < game->map_width * game->map_height && game->map[game->map_y][game->map_x] == 1)
		{
			dof = 8;
			game->distance_H = cos(degrees_to_radians(ray_angle)) * (game->ray_x - game->px) - sin(degrees_to_radians(ray_angle)) * (game->ray_y - game->py);
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
	float ray_angle;
	
	ray = 0;
	ray_angle = fix_angle(game->player_angle + 30);
	while(ray < 60)
	{
		check_vertical(ray_angle, game);
		check_horizontal(ray_angle, game);
		if (game->distance_V < game->distance_H)
		{
			game->ray_x = game->vx;
			game->ray_y = game->vy;
			game->distance_H = game->distance_V;
		}
		ca = fix_angle(game->player_angle - ray_angle);
		game->distance_H = game->distance_H * cos(degrees_to_radians(ca));
		game->lineH = ((64 * 320) / game->distance_H);
		if (game->lineH > 320)
			game->lineH = 320;
		game->lineOffset = 160 - (game->lineH / 2);
		draw_vertical_line(ray * 8 + 200, 0, game->lineOffset, game, 0x00FFFF);
		draw_vertical_line(ray * 8 + 200, game->lineOffset, game->lineH, game, 0xFF0000);
		draw_vertical_line(ray * 8 + 200, game->lineOffset + game->lineH, 640 - game->lineOffset - game->lineH, game, 0x00FF00);
		ray_angle = fix_angle(ray_angle - 1);
		ray++;
	}
}
 */

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
	float	lineOffset;

	ray = 0;
	ray_angle = fix_angle(game->player_angle - FOV2);
	while (ray < game->width)
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
			wall = game->map[(int)ray_y / 32][(int)ray_x / 32];
		}
		distance = distance_between_points(game->px, game->py, ray_x, ray_y);
		distance *= cos(degrees_to_radians(fix_angle(game->player_angle - ray_angle)));
		WallHeight = ((game->height * 32) / distance);
		lineOffset = 160 - (WallHeight / 2);
		draw_vertical_line(ray, 0, lineOffset, game, 0x00FFFF);
		draw_vertical_line(ray, lineOffset, WallHeight, game, 0xFF0000);
		draw_vertical_line(ray, lineOffset + WallHeight, game->height - lineOffset - WallHeight, game, 0x00FF00);
		ray_angle = fix_angle(ray_angle + (FOV / game->width));
		ray++;
	}
}
