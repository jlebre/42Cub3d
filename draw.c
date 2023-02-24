/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:09:59 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 23:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray(int x0, int y0, int x1, int y1, t_game *game)
{
	int fov;

	fov = 0;
	while (fov < 10)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x0 + (x1 * fov) / 5,
				y0 + (y1 * fov) / 5, 0x00FFFF);
		fov++;
	}
}

void	draw_pixel(int x, int y, t_game *game, int color)
{
	if (x >= 0 && x < game->width && y >= 0 && y < game->height)
		mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
	//*(int *)(game->mlx_win + (4 * game->width * y) + (4 * x)) = color;
}

void	draw_a_line(t_game *game)
{
	int x = 500;
	int y = 500;
	int i = 0;

	while (i < 100)
	{
		draw_pixel(x, y, game, 0x00FF00);
		y++;
		i++;
	}
}

/*
static void	predict_wall_face(
	t_ray *ray
)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->mapx += ray->step_x;
		if (ray->step_x == 1)
			ray->side = 0;
		else if (ray->step_x == -1)
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->mapy += ray->step_y;
		if (ray->step_y == 1)
			ray->side = 2;
		else if (ray->step_y == -1)
			ray->side = 3;
	}
}
*/

void draw_wall(int x, int y, int len, int angle, t_game *game)
{
	if ((angle >= 0 && angle <= 45) || (angle > 315 && angle <= 360))
		draw_vertical_line(x, y, len, game, 0x00FF00);
	else if (angle > 45 && angle <= 135)
		draw_vertical_line(x, y, len, game, 0x00FFF0);
	else if (angle > 135 && angle <= 225)
		draw_vertical_line(x, y, len, game, 0x00FFFF);
	else if (angle > 225 && angle <= 315)
		draw_vertical_line(x, y, len, game, 0x000F00);

}

int		draw_vertical_line(int x, int y, int len, t_game *game, int color)
{
	int i;
	int limit;

	i = 0;
	if (x < 0 || x >= game->width)
		return (1);
	limit = game->height;
	while (i < len && (y + i) < limit)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x, y + i, color);
		i++;
	}
	return (1);
}