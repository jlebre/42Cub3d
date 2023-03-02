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
	if (cub->game.map_on == 1)
	{
		if (cub->game.fov_on == 0)
			clear_fov(cub);
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mmbase, 0, 0);
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mmp, cub->px, cub->py);
	}
}

void	init_mini_map(t_cub *cub)
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
				draw_square(cub, x * 16, y * 16, 0x000000FF);
			else if (cub->map.map[y][x] == '0' || cub->map.map[y][x] == 'N'
				|| cub->map.map[y][x] == 'S' || cub->map.map[y][x] == 'E'
				|| cub->map.map[y][x] == 'W')
				draw_square(cub, x * 16, y * 16, 0x00FFFFFF);
			else if (cub->map.map[y][x + 1] != '\0')
				draw_square(cub, x * 16, y * 16, 0x00000000);
			x++;
		}
		y++;
	}
}
