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

/*
	Linha = ponto + vetor direção

	Vetor direção = (x1 - x0, y1 - y0)
*/

void	print_fov(int x0, int y0, t_game *game)
{
	int fov;

	fov = 0;
	while (fov < 20)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x0 + (game->dir_x * fov) / 5,
				y0 + (game->dir_y * fov) / 5, 0x00FF0);
		fov++;
	}
}

void    print_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mmp, game->px, game->py);
	print_fov(game->px + 2.5, game->py + 2.5, game);
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
