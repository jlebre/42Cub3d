/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:22:56 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 01:22:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_s_value(int d)
{
	if (d < 0)
		return (-1);
	else
		return (1);
}

void	print_fov(int x0, int y0, t_game *game)
{
	int	dx;
	int	dy;
	int	sx;
	int sy;
	int dif;
	int i;
	int	fov;

	fov = 0;
	dx = game->dir_x - x0;
	dy = game->dir_y - y0;
	sx = get_s_value(dx);
	sy = get_s_value(dy);
	dif = dx - dy;
	while (fov < 10)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x0, y0, 0x00FF0);
		i = dif * 2;
		if (i > -dy)
		{
			dif -= dy;
			x0 += sx;
		}
		if (i < dx)
		{
			dif += dx;
			y0 += sy;
		}
		fov++;
	}
}

void    print_player(t_game *game)
{
	int	hei;
	int wid;
	int	pixel_size;

	hei = 0;
	wid = 0;
	pixel_size = 6;
	while (hei < pixel_size)
	{
		wid = 0;
		while (wid < pixel_size)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, game->px + wid, game->py + hei, 0x00FF00);
			wid++;
		}
		hei++;
	}
	print_fov(game->px, game->py, game);
}

void	mini_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->blue, x * 34, y * 34);
			else if (game->map[y][x] == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->white, x * 34, y * 34);
			x++;
		}
		y++;
	}
	print_player(game);
}
