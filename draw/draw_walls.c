/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:26:51 by marvin            #+#    #+#             */
/*   Updated: 2023/04/18 23:26:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pos( float ray)
{
	float	unit_dist;
	float	largura;
	float	x_increment;
	float	dir;
	float	wall_x;

	dir = ((int)ray % 16);
	wall_x = (ray - dir);
	unit_dist = (wall_x / dir);
	largura = (unit_dist * 16);
	x_increment = (64 / largura);
	wall_x = wall_x * x_increment;
	return (wall_x);
}

int	get_wall_x(t_cub *cub, float ray_x, float ray_y)
{
	float	wall_x;

	if (check_hit(cub, ray_x, ray_y))
	{
		wall_x = get_pos(ray_y);
		if (ray_x < cub->px)
			wall_x = 64 - wall_x;	
	}
	else
	{
		wall_x = get_pos(ray_x);
		if (ray_y > cub->py)
			wall_x = 64 - wall_x;	
	}
	return (wall_x);
}

void draw_walls(t_cub *cub, int ray, float ray_angle, float ray_x, float ray_y)
{
	float	wall_height;
	float	distance;
	float	fish_eye;
	float	wall_x;

	distance = distance_between_points(cub->px, cub->py, ray_x, ray_y) / 16;
	fish_eye = distance * cos(degrees_to_radians(ray_angle - cub->game.player_angle));
	wall_height = ((cub->height / 2) / fish_eye);
	wall_x = get_wall_x(cub, ray_x, ray_y);
	if (wall_height >= cub->height / 2)
		get_wall_direction(ray, 0, cub->height, cub, wall_x, ray_x, ray_y);
	else
	{
		draw_vertical_line(ray, 0, (int)((cub->height / 2) - wall_height), cub, cub->img.colors[1]);
		get_wall_direction(ray, (int)((cub->height / 2) - wall_height), 2 * wall_height, cub, wall_x, ray_x, ray_y);
		draw_vertical_line(ray, (int)((cub->height / 2) + wall_height), cub->height, cub, cub->img.colors[0]);
	}
}

void		draw_vertical_line(float x, float y, float len, t_cub *cub, int color)
{
	int i;
	int limit;

	i = 0;
	if (x < 0 || x > cub->width)
		return ;
	limit = cub->height;
	while (i < len && (y + i) < limit)
	{
		if (y + i < cub->height && x < cub->width && y + i >= 0 && x >= 0)
			my_mlx_pixel_put(cub, x, y + i, color);
		i++;
	}
}
