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

void	mini_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mmbase, 0, 0);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->blue, x * 16, y * 16);
			else if (game->map[y][x] == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->white, x * 16, y * 16);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mmp, game->py, game->px);
}
