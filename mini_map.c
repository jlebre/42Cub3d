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

void	mini_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map.map[y])
	{
		x = 0;
		while (cub->map.map[y][x])
		{
			if (cub->map.map[y][x] == '1')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.blue, x * 16, y * 16);
			else if (cub->map.map[y][x] == '0' || cub->map.map[y][x] == 'N'
				|| cub->map.map[y][x] == 'S' || cub->map.map[y][x] == 'E'
				|| cub->map.map[y][x] == 'W')
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.white, x * 16, y * 16);
			else if (cub->map.map[y][x + 1])
				mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.black, x * 16, y * 16);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mmp, cub->px, cub->py);
	mlx_pixel_put(cub->mlx, cub->mlx_win, cub->px + cos(degrees_to_radians(cub->game.player_angle)), cub->py + sin(degrees_to_radians(cub->game.player_angle)), 0x000000);
}
