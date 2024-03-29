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

void	draw_mini(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (y < 128 && x < 128 && (y >= 0 && x >= 0))
	{
		dst = cub->game.mini->data + (y * cub->game.mini->size_line
				+ x * (cub->game.mini->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	print_compass(t_cub *cub)
{
	if ((cub->game.player_angle >= 0 && cub->game.player_angle < 23)
		|| (cub->game.player_angle >= 337 && cub->game.player_angle <= 360))
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[0], 570, 410);
	else if (cub->game.player_angle >= 23 && cub->game.player_angle < 68)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[7], 570, 410);
	else if (cub->game.player_angle >= 68 && cub->game.player_angle < 113)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[5], 570, 410);
	else if (cub->game.player_angle >= 113 && cub->game.player_angle < 158)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[4], 570, 410);
	else if (cub->game.player_angle >= 158 && cub->game.player_angle < 203)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[3], 570, 410);
	else if (cub->game.player_angle >= 203 && cub->game.player_angle < 248)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[6], 570, 410);
	else if (cub->game.player_angle >= 248 && cub->game.player_angle < 293)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[2], 570, 410);
	else if (cub->game.player_angle >= 293 && cub->game.player_angle < 337)
		mlx_put_image_to_window(cub->mlx,
			cub->mlx_win, cub->img.compass[1], 570, 410);
}

void	print_map(t_cub *cub)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (cub->px / 4) - 64;
	y = (cub->py / 4) - 64;
	if (x < 0 || cub->map.width16 - x < 64)
		x = 0;
	if (y < 0 || cub->map.height16 - y < 64)
		y = 0;
	if (cub->map.width16 - x < 144)
		x = cub->map.width16 - 144;
	if (cub->map.height16 - y < 128)
		y = cub->map.height16 - 128;
	i = -1;
	while (++i < 128)
	{
		j = -1;
		while (++j < 128)
			draw_mini(cub, j, i,
				my_mlx_pixel_get(cub->game.mmbase, x + j, y + i));
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.bordamm, 6, 6);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->game.mini, 10, 10);
}

void	mini_map(t_cub *cub)
{
	if (cub->game.map_on == 1)
		print_map(cub);
}

void	init_mini_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map.map[y])
	{
		x = 0;
		while (cub->map.map[y][x] && cub->map.map[y][x] != '\n')
		{
			if (cub->map.map[y][x] == '1')
				draw_square(cub, x * 16, y * 16, 0x000000FF);
			else if (cub->map.map[y][x] == '0')
				draw_square(cub, x * 16, y * 16, 0x00FFFFFF);
			else if (cub->map.map[y][x] == ' ')
				draw_square(cub, x * 16, y * 16, 0x00000000);
			else if (cub->map.map[y][x + 1] != '\0')
				draw_square(cub, x * 16, y * 16, 0x00000000);
			x++;
		}
		y++;
	}
}
